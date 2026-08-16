#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/* ====== Original Functions (adapted with ACSL specs) ====== */

/* Function 1: Determine if a/100 >= (5*(a/100))/5 */
uint32_t func1(uint32_t x) {
    uint32_t ans;
    uint32_t a;
    uint32_t b;

    a = x / 100;
    b = (5 * (x / 100)) / 5;

    if (a >= b) {
        ans = 1;
    } else {
        ans = 0;
    }

    return ans;
}

/* Function 2: Compute c - (a - b) with floor at 0 */
/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - (a - b)) < 0 ? 0 : (c - (a - b));
*/

int32_t func2(int32_t a, int32_t b, int32_t c)
{
    int32_t result;
    int32_t raw;

    raw = c - (a - b);
    result = raw < 0 ? 0 : raw;

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;

    return result;
}

/* Function 3: Compute 800*n - 200*(n/15) with bounds */
/*@
    predicate valid_n(integer n) = 1 <= n <= 100;

    logic integer lower_bound(integer n) = 800 * n - 200 * (n / 15);
    logic integer upper_bound(integer n) = 800 * n - 200 * (n / 15 - 1);

    lemma bounds_consistency:
        \forall integer n; valid_n(n) ==> lower_bound(n) <= upper_bound(n);
*/

int func3(unsigned int n) {
    int x;
    int result;

    //@ assert valid_n(n);
    //@ assert 1 <= n <= 100;

    x = 800 * (int)n - 200 * ((int)n / 15);
    //@ assert x == lower_bound(n);

    if (x < 0) {
        result = x - 1;
    } else {
        result = x;
    }

    //@ assert result >= lower_bound(n);
    //@ assert result <= upper_bound(n);

    return result;
}

/* Function 4: Count even/odd numbers and compute score */
/*@ predicate valid_array(int *arr, size_t n) =
      n > 0 && n <= 200 &&
      \forall size_t i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;
*/

/*@ predicate array_length(int *arr, size_t n) =
      \forall size_t i; 0 <= i < n ==> \valid(arr + i);
*/

int func4(size_t n, int *a) {
    size_t i = 0;
    size_t count = 0;
    size_t count2 = 0;
    int result = 0;

    while (i < n) {
        int value = a[i];
        
        //@ assert value > 0 && value <= 1000000000;
        
        if ((value & 1) == 0) {
            count++;
        } else {
            count2++;
        }
        i++;
    }

    //@ assert count >= 0 && count <= n;
    //@ assert count2 >= 0 && count2 <= n;
    
    if (count >= 3) {
        result += 1;
    }
    if (count2 >= 2) {
        result += 1;
    }
    if (count >= 1 && count2 >= 1) {
        result += 1;
    }
    
    //@ assert result >= 0 && result <= 3;
    return result;
}

/* ====== Synthesized Complex Function ====== */

int synthesized_load_balancing_score(
    uint32_t x,          // node capacity parameter for balance check
    int32_t a,           // node priority (higher means more important)
    int32_t b,           // base priority (1 <= b <= a)
    int32_t c,           // current load
    unsigned int n,      // number of tasks assigned to node
    size_t arr_n,        // number of task execution time samples
    int *arr             // array of task execution times
) {
    int final_score = 0;
    
    uint32_t balance_flag = func1(x);
    
    int32_t load_offset = func2(a, b, c);
    
    int base_allocation = func3(n);
    
    int health_score = func4(arr_n, arr);
    
    //@ assert health_score >= 0 && health_score <= 3;
    
    if (balance_flag == 1) {
        final_score = health_score;
    } else {
        int temp = health_score - (int)load_offset;
        final_score = temp > 0 ? temp : 0;
    }
    
    if (final_score > 30) {
        final_score = 30;
    }
    
    //@ assert final_score >= 0 && final_score <= 30;
    
    return final_score;
}
