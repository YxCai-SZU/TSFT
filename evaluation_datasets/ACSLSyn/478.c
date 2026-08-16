#include <stddef.h>
#include <stdbool.h>

/* ========== First function (count items until sum exceeds x) ========== */

/*@ predicate valid_params_count(integer n, integer x) =
      n >= 1 && n <= 100 && x >= 1 && x <= 10000;
*/

/*@ predicate valid_array(integer n, unsigned int *numbers) =
      \valid_read(numbers + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 100;
*/

unsigned int count_until_exceed(unsigned int n, unsigned int x, const unsigned int *numbers) {
    unsigned int sum = 0;
    unsigned int count = 0;
    unsigned int i = 0;
    
    while (i < n && sum <= x) {
        //@ assert numbers[i] >= 1 && numbers[i] <= 100;
        sum += numbers[i];
        count += 1;
        i += 1;
    }
    
    return count;
}

/* ========== Second function (sum elements outside [a, b)) ========== */

/*@
    predicate valid_params_sum(integer n, integer a, integer b) =
        3 <= n && n <= 100 &&
        1 <= a && a < b && b <= n;

    predicate valid_vector(integer n, int *vs) =
        \forall integer i; 0 <= i < n ==> 1 <= vs[i] && vs[i] <= 1000;

    logic integer ans_upper_bound(integer i) = i * 1000;
*/

unsigned int sum_outside_range(unsigned int n, unsigned int a, unsigned int b, int *vs) {
    unsigned int ans = 0;
    unsigned int i = 0;
    
    while (i < n) {
        if (i < a || i >= b) {
            //@ assert 1 <= vs[i] && vs[i] <= 1000;
            ans += (unsigned int)vs[i];
        }
        i++;
    }
    return ans;
}

/* ========== Synthesized function: process two arrays in sequence ========== */

/*@
    predicate valid_inputs(integer n, integer x, integer a, integer b,
                           unsigned int *arr1, int *arr2) =
        valid_params_count(n, x) &&
        valid_array(n, arr1) &&
        valid_params_sum(n, a, b) &&
        \valid(arr2 + (0 .. n-1)) &&
        valid_vector(n, arr2);

    logic integer total_bound(integer n) = (n + 1) + n * 1000;
*/

unsigned int process_arrays(unsigned int n, unsigned int x,
                            unsigned int a, unsigned int b,
                            const unsigned int *arr1, int *arr2)
{
    unsigned int count = count_until_exceed(n, x, arr1);
    unsigned int sum = sum_outside_range(n, a, b, arr2);
    unsigned int total = count + sum;
    
    return total;
}
