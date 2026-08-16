#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 200);
    ensures \result == (a <= x && x - a <= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int c;
    bool result;
    
    if (x < a) {
        //@ assert x < a;
        return false;
    }
    
    //@ assert x >= a;
    c = x - a;
    //@ assert c == ((x) - (a));
    
    result = (c <= b);
    //@ assert result == (a <= x && ((x) - (a)) <= b);
    return result;
}
