#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_product(integer r) = 2 * 3142 * r;
    
    lemma product_bounds: \forall integer r; valid_range(r) ==> 2 * 3142 * 1 <= scaled_product(r) <= 2 * 3142 * 100;
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * 3142 * r / 1000;
*/
int func(int r)
{
    int pi_approx = 3142;
    int scaled_r = r * 1000;
    int product = 2 * pi_approx * r;
    
    //@ assert product == 2 * 3142 * r;
    
    int quotient = 0;
    int remainder = product;
    
    /*@
        loop invariant quotient * 1000 + remainder == product;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 1000)
    {
        quotient += 1;
        remainder -= 1000;
    }
    
    //@ assert quotient * 1000 + remainder == product;
    //@ assert remainder < 1000;
    //@ assert quotient == product / 1000;
    
    return quotient;
}
