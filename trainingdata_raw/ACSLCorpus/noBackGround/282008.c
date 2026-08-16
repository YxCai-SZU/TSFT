#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    ensures \result == (((((a)) * 100) / 2) >= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations
    bool ans;
    
    // Precondition verification
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    // Overflow prevention
    //@ assert a * 100 <= 10000;
    //@ assert (a * 100) / 2 <= 5000;
    
    ans = (a * 100) / 2 >= b;
    
    // Postcondition verification
    //@ assert ans == (((((a)) * 100) / 2) >= b);
    
    return ans;
}
