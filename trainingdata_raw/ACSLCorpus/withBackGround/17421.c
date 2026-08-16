#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_array(size_t n, int64_t *a) =
      n > 0 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
*/

/*@ logic integer ans_upper_bound(integer i) = i * 1000000000; */

/*@ lemma ans_non_negative:
      \forall size_t n, int64_t *a, size_t i, int64_t ans, int64_t prev_height;
      is_valid_array(n, a) && 0 <= i <= n && ans >= 0 && prev_height >= 0 &&
      prev_height <= 1000000000 && ans <= ans_upper_bound(i) ==>
      ans >= 0;
*/

/*@
requires is_valid_array(n, a);
ensures \result >= 0;
*/
int64_t func(size_t n, int64_t *a)
{
    int64_t ans = 0;
    int64_t prev_height = 0;
    size_t i = 0;
    
    /*@
    loop invariant 0 <= i <= n;
    loop invariant ans >= 0;
    loop invariant prev_height >= 0;
    loop invariant prev_height <= 1000000000;
    loop invariant ans <= ans_upper_bound(i);
    loop invariant is_valid_array(n, a);
    loop assigns i, ans, prev_height;
    loop variant n - i;
    */
    while (i < n) {
        //@ assert a[i] > 0 && a[i] <= 1000000000;
        if (a[i] - prev_height < 0) {
            ans += prev_height - a[i];
            //@ assert ans >= 0;
        } else {
            prev_height = a[i];
            //@ assert prev_height >= 0 && prev_height <= 1000000000;
        }
        i += 1;
        //@ assert ans <= ans_upper_bound(i);
    }
    return ans;
}
