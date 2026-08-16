#include <stdint.h>

/*@
    predicate bounds_8(integer x) = 0 <= x <= 8;

    logic integer mul_bounds(integer a, integer b) = a * b;
    //@ lemma mul_bounds_lemma: \forall integer a, b; bounds_8(a) && bounds_8(b) ==> mul_bounds(a, b) <= 64;

    logic integer mul3_bounds(integer a, integer b, integer c) = a * b * c;
    //@ lemma mul3_bounds_lemma: \forall integer a, b, c; bounds_8(a) && bounds_8(b) && bounds_8(c) ==> mul3_bounds(a, b, c) <= 512;

    logic integer mul_add_bounds(integer a, integer b, integer c) = a * b + c;
    //@ lemma mul_add_bounds_lemma: \forall integer a, b, c; bounds_8(a) && bounds_8(b) && bounds_8(c) ==> mul_add_bounds(a, b, c) <= 72;

    logic integer add_bounds(integer b, integer c) = b + c;
    //@ lemma add_bounds_lemma: \forall integer b, c; bounds_8(b) && bounds_8(c) ==> add_bounds(b, c) <= 16;

    logic integer mul_add2_bounds(integer a, integer b, integer c) = a * (b + c);
    //@ lemma mul_add2_bounds_lemma: \forall integer a, b, c; bounds_8(a) && bounds_8(b) && bounds_8(c) ==> mul_add2_bounds(a, b, c) <= 128;
*/

/*@
    requires bounds_8(a) && bounds_8(b) && bounds_8(c);
    ensures \result == a * b * c;
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert a * b <= 64;
    //@ assert a * b * c <= 512;
    uint32_t result;
    result = a * b * c;
    return result;
}

/*@
    requires bounds_8(a) && bounds_8(b) && bounds_8(c);
    ensures \result == a * b + c;
    assigns \nothing;
*/
uint32_t non_linear_arith_example_with_add(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert a * b <= 64;
    //@ assert a * b + c <= 72;
    uint32_t result;
    result = a * b + c;
    return result;
}

/*@
    requires bounds_8(a) && bounds_8(b) && bounds_8(c);
    ensures \result == a * (b + c);
    assigns \nothing;
*/
uint32_t non_linear_arith_example_with_add_2(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert b + c <= 16;
    //@ assert a * (b + c) <= 128;
    uint32_t result;
    result = a * (b + c);
    return result;
}
