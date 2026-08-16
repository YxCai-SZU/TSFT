#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a % 2 != 0 && b % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool a_is_odd;
    bool b_is_odd;
    bool result;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    
    a_is_odd = (a % 2 != 0);
    b_is_odd = (b % 2 != 0);
    
    //@ assert a_is_odd == (a % 2 != 0);
    //@ assert b_is_odd == (b % 2 != 0);
    
    result = a_is_odd && b_is_odd;
    
    //@ assert result == (a % 2 != 0 && b % 2 != 0);
    return result;
}
