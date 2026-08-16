#include <stdint.h>

/*@
    requires (2 <= (a) <= 100 && 2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Declare all variables at the top
    unsigned int result;

    //@ assert 1 <= a - 1 <= 99;
    //@ assert 1 <= b - 1 <= 99;
    //@ assert a - 1 > 0;
    //@ assert b - 1 > 0;
    //@ assert (a - 1) * (b - 1) >= 0;
    //@ assert (a - 1) * (b - 1) < 10000;
    //@ assert (a - 1) * (b - 1) <= 4294967295;

    result = (a - 1) * (b - 1);
    return result;
}
