#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10 && 1 <= (b) <= 10 && 1 <= (c) <= 10);
    ensures \result == (a * b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= 10;
    //@ assert b <= 10;
    //@ assert c <= 10;
    //@ assert a * b <= 100;

    result = (a * b) >= c;
    return result;
}
