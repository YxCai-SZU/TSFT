#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((((n)) * ((n))) * 3);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 * 1 <= ((n) * (n)) && ((n) * (n)) <= 100 * 100;
    
    result = n * n * 3;
    return result;
}
