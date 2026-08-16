#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at scope top
    unsigned long long c;
    bool result;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    
    //@ assert ((a) * (b)) <= 9;
    
    c = a * b;
    
    //@ assert c == ((a) * (b));
    
    result = (c % 2 != 0);
    return result;
}
