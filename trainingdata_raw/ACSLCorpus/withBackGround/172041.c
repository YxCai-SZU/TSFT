#include <limits.h>

/*@ predicate valid_input(integer a, integer b, integer c, integer k) =
      0 <= a && a <= 100 &&
      0 <= b && b <= 100 &&
      0 <= c && c <= 100 &&
      1 <= k && k <= a + b + c &&
      a + b + c >= 1;
*/

/*@ logic integer compute_ans(integer a, integer b, integer c, integer k) =
      \let na = (a < k) ? a : k;
      \let cnt1 = k - na;
      \let nb = (b < cnt1) ? b : cnt1;
      \let nc = c;
      na - nc;
*/

/*@ lemma ans_bounds: \forall integer a, b, c, k;
      valid_input(a, b, c, k) ==>
      compute_ans(a, b, c, k) >= -c &&
      compute_ans(a, b, c, k) <= a &&
      compute_ans(a, b, c, k) <= k;
*/

/*@
  requires valid_input(a, b, c, k);
  ensures \result >= -c && \result <= a && \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int cnt;
    int na;
    int nb;
    int nc;
    int ans;
    
    cnt = k;
    
    //@ assert cnt == k;
    
    if (a < cnt) {
        na = a;
    } else {
        na = cnt;
    }
    //@ assert na == ((a < k) ? a : k);
    
    cnt = cnt - na;
    //@ assert cnt == k - na;
    
    if (b < cnt) {
        nb = b;
    } else {
        nb = cnt;
    }
    //@ assert nb == ((b < k - na) ? b : k - na);
    
    nc = c;
    //@ assert nc == c;
    
    ans = na - nc;
    //@ assert ans == na - nc;
    
    //@ assert ans >= -c && ans <= a && ans <= k;
    
    return ans;
}
