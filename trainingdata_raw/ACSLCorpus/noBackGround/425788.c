#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0) && ((d) > 0);
    requires ((a) <= 10000) && ((b) <= 10000) && ((c) <= 10000) && ((d) <= 10000);
    ensures \result == ((a * b) > (c * d));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at the top
    bool result;

    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    result = (a * b) > (c * d);
    return result;
}
