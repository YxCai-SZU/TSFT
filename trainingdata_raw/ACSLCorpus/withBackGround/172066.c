/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 5000;
    
    logic integer product_mod_2(integer x, integer y) = (x * y) % 2;
    
    lemma product_range: \forall integer x, y; is_valid_range(x) && is_valid_range(y) ==> 1 <= x * y <= 25000000;
*/

#include <stdbool.h>

/*@
    requires is_valid_range(x) && is_valid_range(y);
    ensures \result == (product_mod_2(x, y) == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y) {
    unsigned int product;
    int remainder;
    
    //@ assert 1 <= x && x <= 5000;
    //@ assert 1 <= y && y <= 5000;
    
    product = x * y;
    
    //@ assert 1 <= product && product <= 25000000;
    
    remainder = product;
    
    /*@
        loop invariant 0 <= remainder <= product;
        loop invariant remainder % 2 == product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    /*@
        loop invariant 0 <= remainder < 2;
        loop invariant remainder % 2 == product % 2;
        loop assigns remainder;
        loop variant 2 + remainder;
    */
    while (remainder < 0) {
        remainder += 2;
    }
    
    //@ assert remainder == product % 2;
    
    return remainder == 0;
}
