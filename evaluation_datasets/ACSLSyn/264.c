#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

/* ========== Function 1: vec_tuple_duplicate_test ========== */
/*@
    predicate equal_arrays{L}(unsigned int *a, unsigned int *b, integer len) =
        \forall integer i; 0 <= i < len ==> a[i] == b[i];
*/

bool vec_tuple_duplicate_test(unsigned int *a, unsigned int *b) {
    //@ assert equal_arrays(a, b, 5);
    return true;
}

/* ========== Function 2: compute_adjacent_diffs ========== */

int compute_adjacent_diffs(size_t n, int* x) {
    int x_copy[100];
    size_t i = 0;
    
    while (i < n) {
        //@ assert 0 <= i < n;
        x_copy[i] = x[i];
        i++;
    }

    int ret = 0;
    i = 0;
    
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        //@ assert 1 <= x_copy[i] <= 100;
        //@ assert 1 <= x_copy[i+1] <= 100;
        
        if (x_copy[i] > x_copy[i + 1]) {
            int diff = x_copy[i] - x_copy[i + 1];
            //@ assert diff >= 0;
            ret = ret + diff;
        } else {
            int diff = x_copy[i + 1] - x_copy[i];
            //@ assert diff >= 0;
            ret = ret + diff;
        }
        
        //@ assert ret >= 0;
        //@ assert ret <= (i+1) * 100;
        i++;
    }
    
    //@ assert ret >= 0;
    return ret;
}

/* ========== Function 3: check_identity ========== */
/*@
    predicate bounds(integer n, integer m, integer k) =
        1 <= n <= 1000 &&
        1 <= m <= 1000 &&
        0 <= k <= n * m;

    logic integer product(integer n, integer m) = n * m;
    logic integer difference(integer n, integer m, integer k) = product(n, m) - k;
    logic integer sum(integer s, integer k) = s + k;

    lemma product_bounds: \forall integer n, m;
        bounds(n, m, 0) ==> 0 <= product(n, m) <= 1000000;
    lemma difference_bounds: \forall integer n, m, k;
        bounds(n, m, k) ==> 0 <= difference(n, m, k) <= 1000000;
    lemma sum_bounds: \forall integer n, m, k, s;
        bounds(n, m, k) && s == difference(n, m, k) ==> 0 <= sum(s, k) <= 1000000;
*/

bool check_identity(int n, int m, int k)
{
    int s;
    bool result;

    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= m && m <= 1000;
    //@ assert 0 <= k && k <= n * m;
    //@ assert 0 <= n * m && n * m <= 1000000;
    //@ assert 0 <= n * m - k && n * m - k <= 1000000;

    s = n * m - k;
    //@ assert s == n * m - k;
    //@ assert 0 <= s + k && s + k <= 1000000;

    result = (k == s + k);
    return result;
}

/* ========== Synthesized Function: process_sensor_data ========== */

int process_sensor_data(size_t n, int* x, int rows, int cols, int k,
                        unsigned int *a, unsigned int *b)
{
    bool consistent = vec_tuple_duplicate_test(a, b);
    //@ assert consistent == true;

    int total_variation = compute_adjacent_diffs(n, x);
    //@ assert total_variation >= 0;

    bool identity_holds = check_identity(rows, cols, k);
    //@ assert identity_holds == (k == ((rows * cols - k) + k));

    //@ assert total_variation >= 0 && consistent == true && (identity_holds == (k == ((rows * cols - k) + k)));
    return total_variation;
}
