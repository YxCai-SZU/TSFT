#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100 && 1 <= (c) && (c) <= 200);
    ensures \result == 1 <==> ((c) >= (a) && (c) <= (a) + (b));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    
    if (c >= a && c <= a + b) {
        //@ assert ((c) >= (a) && (c) <= (a) + (b));
        result = true;
    } else {
        //@ assert !((c) >= (a) && (c) <= (a) + (b));
        result = false;
    }
    
    return result;
}
