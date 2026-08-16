#include <stdint.h>

/*@ predicate valid_params(integer a, integer b, integer c) =
      1 <= b && b <= a && a <= 20 &&
      1 <= c && c <= 20;
*/

/*@ logic integer compute_remain(integer a, integer b, integer c) =
      c - (a - b);
*/

/*@ lemma remain_bounds:
      \forall integer a, b, c;
      valid_params(a, b, c) ==>
      compute_remain(a, b, c) <= c;
*/

/*@ lemma result_property:
      \forall integer a, b, c, r;
      valid_params(a, b, c) && r == (compute_remain(a, b, c) < 0 ? 0 : compute_remain(a, b, c)) ==>
      r >= 0 && r <= c && (r == compute_remain(a, b, c) || r == 0);
*/

/*@
  requires valid_params(a, b, c);
  ensures \result >= 0 && \result <= c && (\result == compute_remain(a, b, c) || \result == 0);
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t remain;
    int64_t result;
    
    //@ assert valid_params(a, b, c);
    remain = c - (a - b);
    
    //@ assert remain == compute_remain(a, b, c);
    //@ assert remain <= c;
    
    if (remain < 0) {
        result = 0;
        //@ assert result == 0;
    } else {
        result = remain;
        //@ assert result == remain;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == compute_remain(a, b, c) || result == 0;
    return result;
}
