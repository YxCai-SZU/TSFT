#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 32;

    logic integer safe_product(integer a, integer b, integer c) = 
        (a * b * c) / 2;

    lemma product_bound: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        a * b <= 1024;

    lemma triple_product_bound: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        a * b * c <= 32768;

    lemma half_product_bound: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        (a * b * c) / 2 <= 16384;
*/

/*@
    requires 1 <= a && a <= 32;
    requires 1 <= b && b <= 32;
    requires 1 <= c && c <= 32;
    ensures \result == safe_product(a, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert a * b <= 1024;
    //@ assert a * b * c <= 32768;
    //@ assert (a * b * c) / 2 <= 16384;

    result = (a * b * c) / 2;
    //@ assert result == safe_product(a, b, c);
    return result;
}
