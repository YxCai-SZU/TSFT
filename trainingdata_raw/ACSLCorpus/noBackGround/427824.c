#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((a) < (b) + (c) && (b) < (c) + (a) && (c) < (a) + (b));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;
    //@ assert a + b <= 200;

    if (a < b + c && b < c + a && c < a + b) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
