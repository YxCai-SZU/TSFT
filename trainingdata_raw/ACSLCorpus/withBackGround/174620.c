#include <stdint.h>

/*@ predicate valid_input(integer a, integer b, integer c, integer d) =
      1 <= a && a <= 10000 &&
      1 <= b && b <= 10000 &&
      1 <= c && c <= 10000 &&
      1 <= d && d <= 10000;
*/

/*@ logic integer max(integer x, integer y) =
      x > y ? x : y;
*/

/*@ lemma max_in_range:
      \forall integer a, b;
      1 <= a && a <= 10000 && 1 <= b && b <= 10000 ==>
      1 <= max(a, b) && max(a, b) <= 10000;
*/

/*@ lemma result_cases:
      \forall integer a, b, c, d, result;
      valid_input(a, b, c, d) && result == max(a, b) + max(c, d) ==>
      result == a + c || result == a + d || result == b + c || result == b + d;
*/

/*@ lemma result_bounds:
      \forall integer a, b, c, d, result;
      valid_input(a, b, c, d) && result == max(a, b) + max(c, d) ==>
      2 <= result && result <= 20000;
*/

/*@
  requires valid_input(a, b, c, d);
  ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
  ensures 2 <= \result && \result <= 20000;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max_ab;
    int64_t max_cd;
    int64_t result;

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;

    max_ab = a > b ? a : b;
    //@ assert max_ab == max(a, b);
    //@ assert 1 <= max_ab && max_ab <= 10000;

    max_cd = c > d ? c : d;
    //@ assert max_cd == max(c, d);
    //@ assert 1 <= max_cd && max_cd <= 10000;

    result = max_ab + max_cd;
    //@ assert result == max(a, b) + max(c, d);
    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    //@ assert 2 <= result && result <= 20000;

    return result;
}
