#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate product_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b) ==> 1 <= a * b && a * b <= 10000;
    
    logic integer modulo_two(integer c) = c % 2;
    
    lemma product_bound: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (integer)((a * b) % 2);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t c;
    uint32_t temp;
    int is_even;
    
    //@ assert product_in_range(a, b);
    c = a * b;
    
    temp = c;
    /*@
        loop invariant 0 <= temp <= c;
        loop invariant temp % 2 == c % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    
    is_even = (temp == 0);
    
    if (is_even) {
        return 0;
    } else {
        return 1;
    }
}
