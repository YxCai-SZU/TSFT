#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    
    logic integer product_mod2(integer a, integer b) = (a * b) % 2;
    
    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 9;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product_mod2(a, b) != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool res;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert a * b <= 9;
    
    res = ((a * b) % 2) != 0;
    return res;
}
