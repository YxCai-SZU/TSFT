#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    lemma square_bounds:
        \forall integer a; 1 <= a <= 10 ==> a * a <= 100;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == (a * a % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert a * a <= 100;
    
    result = (a * a % 2 == 0);
    
    return result;
}
