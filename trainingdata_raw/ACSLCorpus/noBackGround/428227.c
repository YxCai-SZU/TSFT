#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    requires (1 <= (b) && (b) <= 10);
    ensures \result == (((a) * (a)) <= ((b) * 10));
    assigns \nothing;
*/
bool test_range(int a, int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert ((a) * (a)) <= 100;
    
    result = (a * a) <= (b * 10);
    return result;
}
