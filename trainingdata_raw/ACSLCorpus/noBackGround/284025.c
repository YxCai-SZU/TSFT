#include <stdbool.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 16 && (m) <= 16 && (n) + (m) <= 16);
    ensures ((\result) == true <==> ((n) <= 8 || (m) <= 8));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;
    
    if (n <= 8 || m <= 8) {
        result = true;
    } else {
        //@ assert n > 8 && m > 8;
        result = false;
    }
    
    return result;
}
