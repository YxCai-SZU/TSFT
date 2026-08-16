#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer sum_mod2(integer a, integer b) = (a + b) % 2;
    
    lemma no_overflow: \forall integer a, b; 0 <= a <= 23 && 0 <= b <= 23 ==> a + b <= 46;
*/

/*@
    requires 0 <= a <= 23;
    requires 0 <= b <= 23;
    ensures \result == ( (a + b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert a + b <= 46;
    
    //@ assert (a + b) % 2 == (a + b) % 2;
    
    result = ((a + b) % 2 == 0);
    return result;
}
