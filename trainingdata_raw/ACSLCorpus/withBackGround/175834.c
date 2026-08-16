#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_whitespace(char c) =
      c == ' ' || c == '\t' || c == '\n' || c == '\r';
*/

/*@ predicate is_eol(char c) =
      c == '\r' || c == '\n';
*/

/*@ predicate valid_params(size_t n, size_t k, size_t* h) =
      1 <= n && n <= 100000 &&
      1 <= k && k <= 500 &&
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= h[i] && h[i] <= 500;
*/

/*@ lemma ans_bounds:
      \forall size_t n, integer i, integer ans;
      0 <= i <= (integer)n && 0 <= ans <= i ==> ans <= (integer)n;
*/

/*@
  requires valid_params(n, k, h);
  ensures \result >= 0 && \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, size_t k, size_t* h)
{
  int ans = 0;
  size_t i = 0;

  /*@ loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= (int)i;
      loop invariant \forall integer j; 0 <= j < n ==> 1 <= h[j] && h[j] <= 500;
      loop assigns ans, i;
      loop variant n - i;
  */
  while (i < n) {
    //@ assert 0 <= i < n;
    if (h[i] >= k) {
      ans += 1;
    }
    i += 1;
  }
  return ans;
}
