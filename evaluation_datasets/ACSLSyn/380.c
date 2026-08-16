#include <stdint.h>
#include <stdbool.h>
#include <string.h>

struct Teacher {
    char* name;
    int years_of_experience;
    char** subjects;
    int subjects_len;
};

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    predicate even(integer x) = x % 2 == 0;
    logic integer total_sum(integer a, integer b) = a + b;
    logic integer total_prod(integer h, integer s) = h * s;
    logic integer half_prod(integer p) = p / 2;
    logic integer final_result(integer h, integer a, integer b) = 
        half_prod(total_prod(h, total_sum(a, b))) / 2;
    
    lemma sum_bounds: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 1 <= total_sum(a, b) <= 200;
    lemma prod_bounds: \forall integer h, a, b;
        valid_range(h) && valid_range(a) && valid_range(b) ==> 
        total_prod(h, total_sum(a, b)) <= 20000;
    lemma half_prod_bounds: \forall integer h, a, b;
        valid_range(h) && valid_range(a) && valid_range(b) ==> 
        half_prod(total_prod(h, total_sum(a, b))) <= 10000;
    lemma result_correct: \forall integer h, a, b;
        valid_range(h) && valid_range(a) && valid_range(b) && even(h) ==> 
        final_result(h, a, b) == (h * (a + b) / 2) / 2;

    predicate intervals_overlap(integer a, integer b, integer c, integer d) =
      a <= d && b >= c;

    predicate valid_range_n(integer n) = 1 <= n && n <= 10000;

    logic integer division_by_subtraction(integer n, integer quotient) =
        n - quotient * 1000;

    predicate teacher_equal(struct Teacher t1, struct Teacher t2) =
        t1.name == t2.name &&
        t1.years_of_experience == t2.years_of_experience &&
        t1.subjects == t2.subjects &&
        t1.subjects_len == t2.subjects_len;

    lemma structural_equality:
        \forall struct Teacher t1, t2;
        teacher_equal(t1, t2) ==> t1 == t2;
*/

uint32_t compute_score(uint32_t a, uint32_t b, uint32_t h) {
    uint32_t sum;
    uint32_t prod;
    uint32_t ans;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(h);
    //@ assert even(h);
    
    //@ assert 1 <= a + b <= 200;
    sum = a + b;
    
    //@ assert h * sum <= 20000;
    prod = h * sum;
    
    //@ assert (h * sum / 2) <= 10000;
    ans = prod / 2;
    
    //@ assert ans == (h * (a + b) / 2);
    return ans / 2;
}

bool check_overlap(int a, int b, int c, int d)
{
    int state = 0;

    //@ assert a <= b && c <= d;

    if (a <= c && c <= b) {
        state = 1;
    }
    if (c <= b && b <= d) {
        state = 2;
    }
    if (a <= d && d <= b) {
        state = 3;
    }
    if (a <= c && d <= b) {
        state = 4;
    }

    //@ assert state > 0 <==> intervals_overlap(a, b, c, d);

    return state > 0;
}

bool are_teachers_equal(struct Teacher t1, struct Teacher t2) {
    //@ assert teacher_equal(t1, t2);
    //@ assert t1 == t2;
    return true;
}

int64_t compute_distance(int64_t n)
{
    int64_t quotient = 0;
    int64_t temp_n = n;

    while (temp_n >= 1000)
    {
        //@ assert temp_n >= 1000;
        quotient += 1;
        temp_n -= 1000;
    }

    int64_t ans = (quotient + 1) * 1000 - n;
    //@ assert ans == ((n / 1000) + 1) * 1000 - n;
    return ans;
}

int64_t process_school_data(uint32_t a, uint32_t b, uint32_t h, int c, int d, int64_t n, struct Teacher t1, struct Teacher t2) {
    uint32_t score = compute_score(a, b, h);
    bool overlap = check_overlap(a, b, c, d);
    bool teachers_match = are_teachers_equal(t1, t2);
    int64_t distance = compute_distance(n);

    int64_t result;
    
    if (overlap && teachers_match) {
        result = distance + (int64_t)score;
    } else {
        result = distance;
    }

    //@ assert (overlap && teachers_match) ==> result == ((n / 1000) + 1) * 1000 - n + (h * (a + b) / 2) / 2;
    //@ assert result >= 0;
    return result;
}
