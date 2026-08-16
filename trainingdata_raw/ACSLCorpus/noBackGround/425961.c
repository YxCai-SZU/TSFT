#include <stdbool.h>

/*@
    requires (0 <= (a) < 100) && (0 <= (b) < 100) && (0 <= (c) < 100);
    ensures \result == (((a) * (b)) < c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (0 <= (a) < 100);
    //@ assert (0 <= (b) < 100);
    //@ assert (0 <= (c) < 100);
    
    //@ assert 0 <= ((a) * (b));
    //@ assert ((a) * (b)) < 10000;
    
    result = (a * b) < c;
    
    //@ assert result == (((a) * (b)) < c);
    
    return result;
}
