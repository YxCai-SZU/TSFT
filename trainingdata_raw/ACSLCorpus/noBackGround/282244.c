#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000000000) && (1 <= (b) <= 1000000000) && (1 <= (c) <= 1000000000);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert a + b >= 2;
    
    if (a + b == c) {
        //@ assert a + b == c || b + c == a || c + a == b;
        result = true;
    } else if (b + c == a) {
        //@ assert a + b == c || b + c == a || c + a == b;
        result = true;
    } else if (c + a == b) {
        //@ assert a + b == c || b + c == a || c + a == b;
        result = true;
    } else {
        //@ assert !(a + b == c || b + c == a || c + a == b);
        result = false;
    }
    
    return result;
}
