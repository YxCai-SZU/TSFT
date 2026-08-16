#include <stdbool.h>

/*@
    requires a <= 100;
    requires b <= 100;
    requires c <= 100;
    ensures \result == (a + b + c >= 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a + b + c >= 0;
    return a + b + c >= 0;
}
