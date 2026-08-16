#include <stdint.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        0 <= a <= 8 && 0 <= b <= 8 && 0 <= c <= 8 && 0 <= d <= 8;

    logic integer product(integer x, integer y) = x * y;
    logic integer sum_of_products(integer a, integer b, integer c, integer d) = 
        product(a, c) + product(b, d);

    lemma product_bound_1:
        \forall integer a, integer c; 0 <= a <= 8 && 0 <= c <= 8 ==> product(a, c) <= 64;

    lemma product_bound_2:
        \forall integer b, integer d; 0 <= b <= 8 && 0 <= d <= 8 ==> product(b, d) <= 64;

    lemma sum_bound:
        \forall integer a, integer b, integer c, integer d;
            bounds(a, b, c, d) ==> sum_of_products(a, b, c, d) <= 128;
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == sum_of_products(a, b, c, d);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert product(a, c) <= 64;
    //@ assert product(b, d) <= 64;
    //@ assert sum_of_products(a, b, c, d) <= 128;
    
    uint32_t res = a * c + b * d;
    return res;
}
