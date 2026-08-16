#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ========== Original function 1: compute score from accuracy and participation ========== */
/*@
    predicate valid_inputs(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;
    
    logic integer compute_k(integer a, integer p) =
        (a * 3 + p) / 2;
    
    logic integer compute_ans(integer a, integer p) =
        compute_k(a, p) / 2;
    
    lemma ans_bound: \forall integer a, p;
        valid_inputs(a, p) ==> compute_ans(a, p) <= a + p;
*/

size_t score_func(size_t a, size_t p)
{
    size_t k;
    size_t ans;
    
    //@ assert valid_inputs(a, p);
    
    k = (a * 3 + p) / 2;
    //@ assert k == compute_k(a, p);
    
    ans = k / 2;
    //@ assert ans == compute_ans(a, p);
    
    //@ assert ans <= a + p;
    
    return ans;
}

/* ========== Original function 2: compute price with discount ========== */
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = 
        (n * 800) - ((n / 15) * 200);

    lemma result_calculation:
        \forall integer n; valid_n(n) ==> compute_result(n) == (n * 800) - ((n / 15) * 200);
*/

int price_func(int n) {
    int x;
    int z;
    unsigned int y;
    
    x = 800 * n;
    //@ assert x == 800 * n;
    
    y = n / 15;
    //@ assert y == n / 15;
    
    z = (int)y * 200;
    //@ assert z == (int)y * 200;
    
    return x - z;
}

/* ========== Original function 3: count elements above threshold ========== */

int min_element(int *a, int len) {
    int min = a[0];
    int i = 1;
    while (i < len) {
        if (a[i] < min) {
            min = a[i];
        }
        i++;
    }
    return min;
}

int count_func(int n, int k, int *h) {
    int sum = 0;
    int index = 0;
    while (index < n) {
        //@ assert sum <= index;
        if (h[index] >= k) {
            sum += 1;
        }
        index += 1;
    }
    return sum;
}

/* ========== Original function 4: check parity ========== */
/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 1000000000;

    lemma loop_decreases: \forall integer c; c > 1 ==> c - 2 < c;
*/

int64_t parity_func(uint64_t a)
{
    uint64_t c;
    int is_even;

    c = a;
    is_even = 1;

    while (c > 1)
    {
        //@ assert c > 1;
        c -= 2;
        is_even = !is_even;
    }

    if (is_even)
    {
        //@ assert is_even != 0;
        return 0;
    }
    else
    {
        //@ assert is_even == 0;
        return 1;
    }
}

/*@
    predicate valid_final_result(integer total_score, integer count, integer base_price) =
        total_score >= 0 && total_score <= (count * 100) + base_price;
*/

int process_exam_data(size_t accuracy, size_t participation, 
                      int num_students, int threshold, int *scores,
                      int base_items)
{
    size_t base_score = score_func(accuracy, participation);
    //@ assert base_score <= accuracy + participation;
    
    int above_count = count_func(num_students, threshold, scores);
    //@ assert above_count >= 0 && above_count <= num_students;
    
    int price_adjustment = price_func(num_students);
    //@ assert price_adjustment == (num_students * 800) - ((num_students / 15) * 200);
    
    int64_t parity_result = parity_func((uint64_t)base_items);
    //@ assert parity_result == 0 || parity_result == 1;
    
    int final_score;
    if (parity_result == 0) {
        final_score = (int)base_score + above_count * 10 + price_adjustment;
    } else {
        final_score = (int)base_score + price_adjustment - above_count * 5;
    }
    
    //@ assert final_score >= 0;
    
    return final_score;
}
