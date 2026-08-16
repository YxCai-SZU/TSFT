#include <stdbool.h>

/*@
    requires (1 <= (input) && (input) <= 1000000000) && (1 <= (k) && (k) <= 1000000000);
    ensures \result == (input >= k * 2 - 1);
*/
bool func(long input, long k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (input) && (input) <= 1000000000) && (1 <= (k) && (k) <= 1000000000);
    
    if (input >= k * 2 - 1) {
        //@ assert input >= k * 2 - 1;
        result = true;
    } else {
        //@ assert !(input >= k * 2 - 1);
        result = false;
    }
    
    return result;
}
