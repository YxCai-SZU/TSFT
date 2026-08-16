#include <stdint.h>

/*@ predicate ans_invariant(integer r, integer pi, integer ans) =
      ans == 2 * r * pi;
*/

/*@ predicate loop_invariant(integer ans, integer div, integer temp) =
      div >= 0 &&
      temp >= 0 &&
      temp == ans - 100 * div;
*/

/*@ lemma division_property:
      \forall integer ans, integer div;
      ans >= 0 && div >= 0 && ans - 100 * div >= 0 && ans - 100 * div < 100 ==>
      div == ans / 100;
*/

/*@
  requires 1 <= r <= 100;
  ensures \result == 2 * r * 314 / 100;
*/
int64_t func(int64_t r) {
    int64_t pi;
    int64_t ans;
    int64_t div;
    int64_t temp;
    
    pi = 314;
    ans = 2 * r * pi;
    div = 0;
    temp = ans;
    
    /*@
      loop invariant 1 <= r <= 100;
      loop invariant pi == 314;
      loop invariant ans_invariant(r, pi, ans);
      loop invariant loop_invariant(ans, div, temp);
      loop assigns div, temp;
    */
    while (temp >= 100) {
        temp -= 100;
        div += 1;
    }
    
    //@ assert div == ans / 100;
    
    return div;
}
