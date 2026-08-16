#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10000;
    
    logic integer product_mod_2(integer a, integer b) = (a * b) % 2;
    
    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product_mod_2(a, b) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product_mod_2;
    bool result;
    
    //@ assert valid_range(a) && valid_range(b);
    
    //@ assert a * b <= 10000 * 10000;
    
    product_mod_2 = (a * b) % 2;
    
    //@ assert product_mod_2 == (a * b) % 2;
    
    result = (product_mod_2 == 1);
    
    //@ assert result == (product_mod_2 == 1);
    
    return result;
}
