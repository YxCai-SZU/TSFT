#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

/* Scenario: A simplified student exam score processing system.
   The system takes a student's scores in two subjects (each 1-10), 
   a student ID (1-100), a grade level (1-3), and an array of two scores (1-100 each).
   It computes a final score and determines if the student qualifies for an award.
   The data flow: 
     1. func1 computes a capped combined score from two subject scores
     2. func2 checks if the student ID meets a threshold
     3. func3 computes a complementary grade level value
     4. func4 computes an average from two additional scores
   The synthesized function determines award eligibility based on these computations.
*/

/* Original function 1: compute capped combined score */
/*@
    predicate valid_range_1(integer x) = 0 <= x <= 10;
    
    logic integer compute(integer x, integer y) = x + y * 3;
    
    lemma compute_bounds:
        \forall integer x, y; valid_range_1(x) && valid_range_1(y) ==> 
            0 <= compute(x, y) <= 40;
*/

int func1(int x, int y) {
    //@ assert valid_range_1(x);
    //@ assert valid_range_1(y);
    //@ assert y * 3 <= 30;
    //@ assert x + y * 3 <= 40;
    
    int ans;
    if (x + y * 3 < 20) {
        ans = x + y * 3;
    } else {
        ans = 20;
    }
    return ans;
}

/* Original function 2: check threshold */
/*@
    predicate is_result(integer n, bool result) =
        result == (n >= 13 || n == 12);
*/

bool func2(unsigned long n)
{
    bool result;

    //@ assert 1 <= n <= 100;

    if (n < 13 && n != 12)
    {
        //@ assert n < 13 && n != 12;
        result = false;
    }
    else
    {
        //@ assert n >= 13 || n == 12;
        result = true;
    }

    //@ assert is_result(n, result);
    return result;
}

/* Original function 3: compute complementary value */
/*@
    predicate valid_range_3(integer v) = 1 <= v <= 3;

    logic integer compute_result(integer a, integer b) = 6 - a - b;

    lemma result_bounds: \forall integer a, b;
        valid_range_3(a) && valid_range_3(b) && a != b ==>
        valid_range_3(compute_result(a, b));
*/

int func3(unsigned int a, unsigned int b)
{
    int x;

    x = 6;

    if (a == 1)
    {
        x = x - 1;
    }
    else if (a == 2)
    {
        x = x - 2;
    }
    else
    {
        x = x - 3;
    }

    //@ assert x == 6 - a;

    if (b == 1)
    {
        x = x - 1;
    }
    else if (b == 2)
    {
        x = x - 2;
    }
    else
    {
        x = x - 3;
    }

    //@ assert x == compute_result(a, b);

    return x;
}

/* Original function 4: compute average from array */
/*@
    predicate is_even_sum(integer s, integer count) =
        s == 2 * count;
*/

/*@
    lemma sum_bounds:
        \forall integer v0, v1;
            1 <= v0 <= 100 && 1 <= v1 <= 100 ==> 2 <= v0 + v1 <= 200;
*/

int func4(size_t v[2]) {
    size_t sum;
    int avg;
    bool is_even;
    size_t temp_sum;
    size_t count;

    sum = v[0] + v[1];
    avg = 0;
    is_even = false;
    temp_sum = sum;
    count = 0;

    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    if (temp_sum == 0) {
        is_even = true;
    }

    if (is_even) {
        avg = (int)count;
        //@ assert avg * 2 == sum;
        return avg;
    } else {
        return -1;
    }
}

/* Synthesized function: determine award eligibility */
int award_check(int s1, int s2, unsigned long student_id, 
                unsigned int grade1, unsigned int grade2, size_t scores[2]) {
    int result = 0;
    
    int capped_score = func1(s1, s2);
    
    bool meets_threshold = func2(student_id);
    
    int grade_complement = func3(grade1, grade2);
    
    int avg_score = func4(scores);
    
    if (capped_score >= 10 && meets_threshold && grade_complement >= 2 && avg_score >= 0) {
        result = 1;
    }
    
    //@ assert (result == 1) ==> (capped_score >= 10 && meets_threshold && grade_complement >= 2 && avg_score >= 0);
    return result;
}
