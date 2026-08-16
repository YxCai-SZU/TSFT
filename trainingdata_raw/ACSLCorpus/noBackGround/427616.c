#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (a) <= 100 && (b) <= 100 && (c) <= 100);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a <= 100 && b <= 100 && c <= 100;
    return a < b && b < c;
}
