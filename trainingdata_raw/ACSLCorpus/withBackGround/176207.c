#include <stdint.h>

/*@
    predicate valid_input(uint32_t a, uint32_t b, uint32_t c, uint32_t d) =
        a <= 4294967295 &&
        b <= 4294967295 &&
        c <= 4294967295 &&
        d <= 4294967295 &&
        (integer)a * (integer)b <= 4294967295 &&
        (integer)c * (integer)d <= 4294967295 &&
        (integer)a * (integer)b + (integer)c * (integer)d <= 4294967295;

    logic integer product_sum(integer a, integer b, integer c, integer d) =
        a * b + c * d;

    lemma product_bound:
        \forall integer a, b, c, d;
            a <= 4294967295 && b <= 4294967295 && c <= 4294967295 && d <= 4294967295 &&
            a * b <= 4294967295 && c * d <= 4294967295 && a * b + c * d <= 4294967295 ==>
            a * b + c * d <= 4294967295;
*/

/*@
    requires valid_input(a, b, c, d);
    ensures \result == product_sum(a, b, c, d);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert a * b <= 4294967295;
    //@ assert c * d <= 4294967295;
    //@ assert a * b + c * d <= 4294967295;
    
    uint32_t prod = a * b + c * d;
    return prod;
}
