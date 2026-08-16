#include <stdint.h>
#include <stddef.h>

/*@ predicate valid_array(int64_t *a, size_t n) =
      n >= 1 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000;
*/

/*@ predicate valid_params(size_t n, size_t m) =
      1 <= n && n <= 100000 && 0 <= m && m <= n - 1;
*/

/*@ logic integer max_possible_sum(integer i) = i * 1000000; */

/*@ lemma sum_bounds:
      \forall integer sum, integer i;
      sum >= 0 && sum <= max_possible_sum(i) ==> sum >= 0;
*/


int64_t func(size_t n, size_t m, int64_t *a)
{
    int64_t sum = 0;
    size_t i = 0;
    int64_t ans = 0;
    
    // First loop: sum all elements
    
    while (i < n)
    {
        //@ assert a[i] >= 1 && a[i] <= 1000000;
        sum += a[i];
        i++;
        //@ assert sum >= 0;
    }
    
    // Second loop: sum first m elements
    i = 0;
    
    while (i < m)
    {
        //@ assert a[i] >= 1 && a[i] <= 1000000;
        ans += a[i];
        i++;
        //@ assert ans >= 0;
    }
    
    // Final calculation
    if (sum - 2 * ans >= 0)
    {
        ans = sum - 2 * ans;
    }
    else
    {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    return ans;
}
