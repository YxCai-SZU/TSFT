#include <stdbool.h>

/*@
    requires a <= 16 && b <= 16;
    ensures \result == (a * b == 100);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert a * b <= 16 * 16;
    return a * b == 100;
}

/*@
    requires a <= 16 && b <= 16;
    ensures \result == (a * b == 100);
    assigns \nothing;
*/
bool func2(unsigned int a, unsigned int b)
{
    //@ assert a * b <= 16 * 16;
    //@ assert a * b >= 0 * 0;
    return a * b == 100;
}
