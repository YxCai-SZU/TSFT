#include <stdint.h>

/*@ predicate min_ab_is_a_or_b(integer a, integer b, integer min_ab) =
      (a < b ==> min_ab == a) && (b <= a ==> min_ab == b);
*/

/*@ predicate min_cd_is_c_or_d(integer c, integer d, integer min_cd) =
      (c < d ==> min_cd == c) && (d <= c ==> min_cd == d);
*/

/*@ lemma lemma_min_ab:
      \forall integer a, b, min_ab;
        1 <= a <= 10000 && 1 <= b <= 10000 && min_ab_is_a_or_b(a, b, min_ab) ==>
        min_ab == a || min_ab == b;
*/

/*@ lemma lemma_min_cd:
      \forall integer c, d, min_cd;
        1 <= c <= 10000 && 1 <= d <= 10000 && min_cd_is_c_or_d(c, d, min_cd) ==>
        min_cd == c || min_cd == d;
*/

/*@
  requires 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000;
  ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t min_ab;
    uint64_t min_cd;
    uint64_t result;

    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000;
    if (a < b) {
        min_ab = a;
        //@ assert min_ab_is_a_or_b(a, b, min_ab);
    } else {
        min_ab = b;
        //@ assert min_ab_is_a_or_b(a, b, min_ab);
    }

    //@ assert 1 <= c <= 10000 && 1 <= d <= 10000;
    if (c < d) {
        min_cd = c;
        //@ assert min_cd_is_c_or_d(c, d, min_cd);
    } else {
        min_cd = d;
        //@ assert min_cd_is_c_or_d(c, d, min_cd);
    }

    //@ assert min_ab_is_a_or_b(a, b, min_ab);
    //@ assert min_cd_is_c_or_d(c, d, min_cd);
    result = min_ab + min_cd;
    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    return result;
}
