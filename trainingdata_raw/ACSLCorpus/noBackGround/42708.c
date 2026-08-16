#include <stdint.h>

/*@
    requires -1000 <= x <= 1000;
    ensures \result == x * x * x;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    //@ assert -1000 <= x && x <= 1000;
    //@ assert -1000000 <= x * x && x * x <= 1000000;
    //@ assert -1000000000 <= x * x * x && x * x * x <= 1000000000;
    //@ assert x * x * x == x * x * x;
    return x * x * x;
}
