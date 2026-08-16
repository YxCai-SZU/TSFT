#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> (((a) <= (c) && (c) <= (b)) || ((b) <= (c) && (c) <= (a)));
 */
bool func(int a, int b, int c)
{
    bool result;
    //@ assert a != b && b != c && a != c;
    
    if ((a <= c && c <= b) || (b <= c && c <= a)) {
        //@ assert (((a) <= (c) && (c) <= (b)) || ((b) <= (c) && (c) <= (a)));
        result = true;
    } else {
        //@ assert !(((a) <= (c) && (c) <= (b)) || ((b) <= (c) && (c) <= (a)));
        result = false;
    }
    
    return result;
}
