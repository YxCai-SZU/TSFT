#include <stdbool.h>

/*@
    requires (1 <= (K) && (K) <= 100) && (1 <= (X) && (X) <= 100000);
    ensures \result == (500 * K >= X);
    assigns \nothing;
*/
bool func(int K, int X)
{
    bool result;
    
    //@ assert (1 <= (K) && (K) <= 100) && (1 <= (X) && (X) <= 100000);
    
    if (500 * K >= X) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
