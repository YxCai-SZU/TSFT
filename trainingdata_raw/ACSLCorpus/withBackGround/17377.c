#include <stdint.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_medium(integer x) = 1 <= x <= 20;
*/

/*@
    requires is_medium(a) && is_medium(b);
    ensures (is_small(a) && is_small(b)) ==> \result == a * b;
    ensures (!is_small(a) || !is_small(b)) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    int32_t result;

    //@ assert is_medium(a) && is_medium(b);
    
    if (a > 9 || b > 9) {
        //@ assert !is_small(a) || !is_small(b);
        result = -1;
        return result;
    }
    
    //@ assert is_small(a) && is_small(b);
    
    product = a * b;
    //@ assert product <= 81;
    
    result = (int32_t)product;
    //@ assert result == a * b;
    return result;
}
