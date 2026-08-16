#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (c <= b && a + b >= d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a + b <= 200;
    
    if (c <= b && a + b >= d) {
        result = true;
    } else {
        //@ assert !(c <= b && a + b >= d);
        result = false;
    }
    
    return result;
}
