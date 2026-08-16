#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    requires ((a) != (b) && (b) != (c) && (a) != (c));
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
    
    if (a < b && b < c) {
        //@ assert a < b && b < c;
        return true;
    } else {
        //@ assert !(a < b && b < c);
        return false;
    }
}
