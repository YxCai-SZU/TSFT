#include <stdbool.h>

/*@
    predicate is_product_le(integer x, integer y, integer limit) =
        x * y <= limit;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y;
        x > 0 && y > 0 && x <= 10000 && y <= 10000 ==> x * y <= 10000 * 10000;
*/

/*@
    requires x > 0 && y > 0;
    requires x <= 10000 && y <= 10000;
    ensures \result == true <==> x * y <= 10000;
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int product;
    bool result;

    //@ assert x > 0 && y > 0;
    
    //@ assert x <= 10000 && y <= 10000;
    
    //@ assert x * y <= 10000 * 10000;
    
    product = x * y;
    
    //@ assert product == x * y;
    
    result = (product <= 10000);
    
    //@ assert result == true <==> product <= 10000;
    
    return result;
}
