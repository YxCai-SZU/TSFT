#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    //@ assert 1 <= a * b <= 100000000;
    
    result = ((a * b) % 2 == 0);
    
    //@ assert result == ((a * b) % 2 == 0);
    return result;
}
