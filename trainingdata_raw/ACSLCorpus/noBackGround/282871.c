#include <stdbool.h>
/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= c <= 1000000000;
    ensures \result == true <==> c >= a && c <= a + b;
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= 1000000000;
    //@ assert b <= 1000000000;
    //@ assert c <= 1000000000;
    //@ assert a + b <= 2147483647;

    if (c >= a && c <= a + b) {
        //@ assert c >= a && c <= a + b;
        result = true;
    } else {
        //@ assert !(c >= a && c <= a + b);
        result = false;
    }

    return result;
}
