#include <stdbool.h>

/*@
    requires a > 0;
    requires b > 0;
    requires c > 0;
    requires a + b + c == 180;
    ensures \result == (a == 60 && b == 60 && c == 60);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a + b + c == 180;
    return (a == 60 && b == 60 && c == 60);
}
