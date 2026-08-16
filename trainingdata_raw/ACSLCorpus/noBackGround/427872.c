#include <stdbool.h>

/*@
    requires a <= b;
    requires b <= 1000000000;
    requires a >= 1;
    requires c >= 1;
    requires c <= 1000000000;
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at the top
    bool result;

    //@ assert a <= b;
    //@ assert b <= 1000000000;
    //@ assert a >= 1;
    //@ assert c >= 1;
    //@ assert c <= 1000000000;

    if (a <= c && c <= b) {
        //@ assert a <= c && c <= b;
        result = true;
    } else {
        //@ assert !(a <= c && c <= b);
        result = false;
    }

    return result;
}
