#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds: 
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product(a, b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool is_odd;
    unsigned int temp;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    product = a * b;
    
    //@ assert 1 <= product && product <= 10000;
    
    is_odd = false;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 1)
    {
        is_odd = true;
    }
    
    //@ assert is_odd == (product % 2 != 0);
    
    return is_odd;
}
