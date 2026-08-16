#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 0 <= a <= 100;
    predicate b_in_range(integer b) = 0 <= b <= 100;
    predicate x_in_range(integer x) = 0 <= x <= 100;
    
    logic integer sum_ab(integer a, integer b) = a + b;
    
    lemma sum_bound: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> sum_ab(a, b) <= 200;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a + b <= 200;
    //@ assert x <= 100 && a <= 100;
    
    result = (x <= a + b) && (a <= x);
    
    //@ assert result == (x <= a + b && a <= x);
    return result;
}
