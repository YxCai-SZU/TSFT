#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_index_range(integer i, integer n) = 0 <= i < n; */
/*@ predicate valid_height(integer h) = 1 <= h && h <= 500; */
/*@ predicate valid_n(integer n) = 1 <= n && n <= 100000; */
/*@ predicate valid_k(integer k) = 1 <= k && k <= 500; */

/*@
  lemma height_bounds:
    \forall integer h; valid_height(h) ==> 1 <= h && h <= 500;
*/

/*@
  requires 
    valid_n(n) && valid_k(k) && 
    \valid_read(h + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> valid_height(h[i]);
  ensures 
    0 <= \result <= (int)n;
*/
int func(size_t n, size_t k, const int* h)
{
  int ans = 0;
  size_t i = 0;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant 0 <= ans <= (int)i;
    loop invariant \forall integer j; 0 <= j < i ==> valid_height(h[j]);
    loop assigns i, ans;
    loop variant n - i;
  */
  while (i < n) {
    //@ assert valid_index_range(i, n);
    if (h[i] >= (int)k) {
      ans += 1;
    }
    i += 1;
  }
  return ans;
}
