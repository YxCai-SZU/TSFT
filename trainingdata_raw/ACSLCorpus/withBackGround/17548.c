#include <stdbool.h>

/*@
    predicate product_in_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100 ==> x * y <= 100 * 100;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    ensures \result == true <==> (x * y) / 2 <= z;
    assigns \nothing;
*/
bool func(unsigned long long x, unsigned long long y, unsigned long long z)
{
    unsigned long long product;
    bool result;

    //@ assert product_in_range(x, y);
    product = x * y;
    result = (product / 2 <= z);
    
    //@ assert result == true <==> (product / 2 <= z);
    return result;
}
