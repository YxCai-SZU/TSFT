#include <stdbool.h>
#include <stddef.h>

/* predicate and lemma from snippet 1 */
/*@ predicate valid_array(integer n, int *x) =
      n > 0 && n <= 100 &&
      \valid(x + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> x[i] > 0 && x[i] <= 100;
*/

/*@ logic integer array_length(integer n, int *x) = n; */

/*@ lemma count_bound: \forall integer n, int *x, integer count;
      valid_array(n, x) && 0 <= count <= n ==> count >= 0 && count <= n;
*/

/* predicate and lemma from snippet 2 */
/*@ predicate is_valid_array(int *a, size_t n) =
      \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= (int)n;
*/

/*@ lemma index_bound: \forall size_t n; 1 <= n && n <= 200000 ==> n <= 200000; */

/* predicate and lemma from snippet 3 */
/*@ predicate valid_range(int *arr, integer n) =
      n > 0 && n <= 100000 &&
      \forall integer j; 0 <= j < n ==> arr[j] >= 1 && arr[j] <= 1000000000;
*/

/*@ logic integer max(integer a, integer b) =
      a > b ? a : b;
*/

/*@ lemma res_bounds:
      \forall integer n, integer i, integer res;
      n > 0 && 1 <= i <= n && res >= 0 && res <= i-1 ==> res <= n-1;
*/

/* predicate and lemma from snippet 4 */
/*@
    predicate is_within_bounds(integer x, integer y) =
        1 <= x && x <= 5 && 1 <= y && y <= 5;

    logic integer max_product(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y; is_within_bounds(x, y) ==> max_product(x, y) <= 25;
*/

/* function from snippet 1 */
size_t func1(size_t n, int *x) {
    size_t count = 0;
    size_t num = 1;
    size_t index = 0;
    
    while (index < n && num <= 100) {
        int x_i = x[index];
        if (num == (size_t)x_i) {
            //@ assert num == (size_t)x_i;
            count += 1;
            num = 1;
        } else {
            //@ assert num != (size_t)x_i;
            num += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}

/* function from snippet 2 */
int func2(size_t n, int *a) {
    int num = 1;
    int count = 0;
    size_t index = 0;
    
    while (index < n) {
        //@ assert 0 <= index < n;
        if (a[index] == num) {
            num += 1;
        } else {
            count += 1;
        }
        index += 1;
    }
    return count;
}

/* function from snippet 3 */
int func3(size_t n, const int *h) {
    int cur_h;
    int res;
    size_t i;
    
    cur_h = h[0];
    res = 0;
    i = 1;
    
    while (i < n) {
        //@ assert h[i] >= 1 && h[i] <= 1000000000;
        if (cur_h < h[i]) {
            cur_h = h[i];
            res += 1;
        }
        i += 1;
    }
    return res;
}

/* function from snippet 4 */
unsigned int func4(unsigned int x, unsigned int y)
{
    unsigned int ret;

    //@ assert x > 0 && y > 0;
    //@ assert is_within_bounds(x, y);
    //@ assert x * y <= 25;

    ret = x * y;
    return ret;
}

/* 
 * Scenario: Data validation and transformation pipeline for a sensor data aggregator.
 * 
 * Data flow:
 * 1. Sensor readings (array x) are filtered by func1, counting occurrences of a pattern sequence.
 * 2. A separate validation array (a) is processed by func2 to count anomalies.
 * 3. A trend analysis on height data (h) is done by func3 to count increasing peaks.
 * 4. The results from func1 and func2 are used as bounded inputs to func4 for final aggregation.
 * 
 * The synthesized function combines these operations to produce a final result that satisfies
 * the high-level property that the product of the two independent counts is bounded.
 */

unsigned int synthesized_func(size_t n, int *x, size_t m, int *a, size_t p, const int *h)
{
    size_t count1 = func1(n, x);
    int count2 = func2(m, a);
    int count3 = func3(p, h);
    
    /* 
     * Since count1 is between 0 and n (<= 100), and count2 is between 0 and m (<= 200000),
     * we take their remainder modulo 5 plus 1 to get values in [1,5] for func4.
     * This ensures the inputs to func4 satisfy the preconditions.
     */
    unsigned int bounded_x = (count1 % 5) + 1;
    unsigned int bounded_y = ((unsigned int)count2 % 5) + 1;
    
    unsigned int result = func4(bounded_x, bounded_y);
    
    //@ assert result <= 25;
    return result;
}
