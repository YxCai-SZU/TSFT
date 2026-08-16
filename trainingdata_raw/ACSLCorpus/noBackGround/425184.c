#include <stdbool.h>

/*@
    requires ((a) <= (b) &&
        (a) >= -100 &&
        (b) <= 100 &&
        (c) >= -100 &&
        (c) <= 100);
    ensures ((\result) == ((a) <= (c) && (c) <= (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert c >= -100;
    //@ assert c <= 100;
    
    bool result;
    
    result = (a <= c && c <= b);
    
    return result;
}
