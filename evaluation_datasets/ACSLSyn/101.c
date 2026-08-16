#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* ==================== First Underlying Function (from snippet 1) ==================== */

/*@
    predicate valid_params(integer n, integer x, int *l) =
        1 <= n && n <= 100 &&
        1 <= x && x <= 10000 &&
        \valid(l + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= l[i] && l[i] <= 100;

    logic integer element_sum{L}(int *l, integer i) =
        i <= 0 ? 0 : element_sum(l, i-1) + \at(l[i-1], L);

    lemma sum_bounds:
        \forall int *l, integer n, integer i;
        valid_params(n, 0, l) && 0 <= i <= n ==>
        0 <= element_sum(l, i) && element_sum(l, i) <= i * 100;
*/

size_t count_prefix_le(size_t n, int x, int *l)
{
    size_t count = 0;
    int sum = 0;
    size_t i = 0;
    
    while (i < n)
    {
        //@ assert i < n;
        sum += l[i];
        
        if (sum <= x)
        {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}

/* ==================== Second Underlying Function (from snippet 2) ==================== */

/*@ predicate sorted(int64_t* a, integer n) =
      \forall integer i; 0 <= i < n - 1 ==> a[i] < a[i + 1];
*/

/*@ predicate valid_array(int64_t* a, integer n) =
      \forall integer i; 0 <= i < n ==> 0 <= a[i] <= 1000000000;
*/

/*@ lemma acc_bounds:
      \forall integer i; 0 <= i <= 49 ==>
      -1000000000 * i <= 0 <= 1000000000 * i;
*/

int64_t count_adj_diff_le(int64_t n, int64_t x, int64_t* a) {
    int64_t ans = 0;
    int64_t i = 0;
    int64_t acc = 0;
    
    while (i < n - 1) {
        acc += a[i] - a[i + 1];
        //@ assert -1000000000 * (i + 1) <= acc <= 1000000000 * (i + 1);
        if (acc <= x) {
            ans += 1;
        }
        i += 1;
        //@ assert 0 <= ans <= i;
    }
    return ans;
}

/* ==================== Synthesized Function ==================== */

/*@
    predicate valid_merged_input(integer n, int x1, int64_t x2, int *l, int64_t *a, integer m) =
        valid_params(n, x1, l) &&
        2 <= m <= 50 &&
        0 <= x2 <= 1000000000 &&
        \valid(a + (0..m-1)) &&
        valid_array(a, m) &&
        sorted(a, m) &&
        n == (integer)m &&
        x1 <= 10000;
*/

int64_t analyze_packet_stream(size_t n, int x1, int64_t x2, int *l, int64_t *a)
{
    size_t count_small = count_prefix_le(n, x1, l);
    
    int64_t count_large = count_adj_diff_le((int64_t)n, x2, a);
    
    int64_t total = (int64_t)count_small + count_large;
    
    //@ assert total >= 0 && total <= (int64_t)(n + 1) + (int64_t)(n - 1);
    
    return total;
}
