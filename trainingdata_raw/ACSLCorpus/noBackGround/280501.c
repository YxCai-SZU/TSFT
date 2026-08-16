#include <limits.h>

/*@
    requires (2 <= (x) <= 100);
    requires (2 <= (y) <= 100);
    ensures \result == ((x) * (y) - (x) - (y) + 1);
    assigns \nothing;
*/
int func(int x, int y)
{
    unsigned int x_unsigned;
    unsigned int y_unsigned;
    unsigned int result_unsigned;

    x_unsigned = (unsigned int)x;
    y_unsigned = (unsigned int)y;

    //@ assert x_unsigned + 1 <= 101;
    //@ assert y_unsigned + 1 <= 101;
    //@ assert x_unsigned * y_unsigned <= 10000;
    //@ assert x_unsigned * y_unsigned - x_unsigned >= 0;
    //@ assert x_unsigned * y_unsigned - x_unsigned - y_unsigned >= 0;

    result_unsigned = (x_unsigned * y_unsigned) - x_unsigned - y_unsigned + 1;
    return (int)result_unsigned;
}
