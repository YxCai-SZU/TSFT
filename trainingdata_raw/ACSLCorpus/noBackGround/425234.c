#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 200);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(int a, int b, int x)
{
    bool result;
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (x) && (x) <= 200);
    
    if (a <= x && a + b >= x) {
        //@ assert a <= x && a + b >= x;
        result = true;
    } else {
        //@ assert !(a <= x && a + b >= x);
        result = false;
    }
    
    return result;
}
