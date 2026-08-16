#include <stdbool.h>

/*@
    requires (0 <= (a) <= 50) && (0 <= (b) <= 50) && (0 <= (c) <= 50);
    ensures \result == true <==> a + b >= c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (0 <= (a) <= 50);
    //@ assert (0 <= (b) <= 50);
    //@ assert (0 <= (c) <= 50);
    
    //@ assert ((a) + (b)) <= 100;
    
    if (a + b < c) {
        //@ assert a + b < c;
        result = false;
    } else {
        //@ assert a + b >= c;
        result = true;
    }
    
    return result;
}
