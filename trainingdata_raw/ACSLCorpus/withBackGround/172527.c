#include <stdint.h>

/*@
    predicate is_one_of(integer result, integer a, integer b, integer c, integer d, integer e) =
        result == a || result == b || result == c || result == d || result == e;

    predicate is_greater_or_equal(integer result, integer a, integer b, integer c, integer d, integer e) =
        result >= a && result >= b && result >= c && result >= d && result >= e;

    lemma max_abc_property:
        \forall integer a, b, c, d, e, max_ab, max_bc, max_cd, max_de, max_abc, max_cde;
        max_ab == (a > b ? a : b) &&
        max_bc == (b > c ? b : c) &&
        max_cd == (c > d ? c : d) &&
        max_de == (d > e ? d : e) &&
        max_abc == (max_ab > max_bc ? max_ab : max_bc) &&
        max_cde == (max_cd > max_de ? max_cd : max_de) &&
        max_abc > max_cde ==>
        is_greater_or_equal(max_abc, a, b, c, d, e);

    lemma max_cde_property:
        \forall integer a, b, c, d, e, max_ab, max_bc, max_cd, max_de, max_abc, max_cde;
        max_ab == (a > b ? a : b) &&
        max_bc == (b > c ? b : c) &&
        max_cd == (c > d ? c : d) &&
        max_de == (d > e ? d : e) &&
        max_abc == (max_ab > max_bc ? max_ab : max_bc) &&
        max_cde == (max_cd > max_de ? max_cd : max_de) &&
        max_abc <= max_cde ==>
        is_greater_or_equal(max_cde, a, b, c, d, e);
*/

/*@
    requires \true;
    ensures is_one_of(\result, a, b, c, d, e);
    ensures is_greater_or_equal(\result, a, b, c, d, e);
*/
uint32_t find_max(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t max_ab;
    uint32_t max_bc;
    uint32_t max_cd;
    uint32_t max_de;
    uint32_t max_abc;
    uint32_t max_cde;
    uint32_t result;

    max_ab = a > b ? a : b;
    max_bc = b > c ? b : c;
    max_cd = c > d ? c : d;
    max_de = d > e ? d : e;

    max_abc = max_ab > max_bc ? max_ab : max_bc;
    max_cde = max_cd > max_de ? max_cd : max_de;

    if (max_abc > max_cde) {
        //@ assert is_greater_or_equal(max_abc, a, b, c, d, e);
        result = max_abc;
    } else {
        //@ assert is_greater_or_equal(max_cde, a, b, c, d, e);
        result = max_cde;
    }

    //@ assert is_one_of(result, a, b, c, d, e);
    return result;
}
