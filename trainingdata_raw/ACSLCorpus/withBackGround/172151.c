/*@
    predicate bounds(integer a, integer b) = 0 <= a && a <= 10 && 0 <= b && b <= 10;
    predicate product_bounded(integer a, integer b) = a * b <= 100;
    
    lemma bounds_imply_product_bounded: 
        \forall integer a, b; bounds(a, b) ==> product_bounded(a, b);
*/

#include <stdint.h>

/*@
    requires 0 <= a && a <= 10 && 0 <= b && b <= 10;
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert bounds(a, b);
    //@ assert product_bounded(a, b);
    
    result = a * b;
    
    //@ assert result == a * b;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    // Variable declarations at top of scope
    uint32_t res;
    
    res = func(5, 5);
    
    return 0;
}
