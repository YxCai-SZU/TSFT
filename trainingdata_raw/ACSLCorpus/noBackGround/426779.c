#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a * 3 <= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    //@ assert a <= 100;
    
    result = (a * 3) <= b;
    
    //@ assert result == (a * 3 <= b);
    return result;
}
