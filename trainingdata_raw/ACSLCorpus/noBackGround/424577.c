#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500 &&
        1 <= (b) <= 500 &&
        1 <= (c) <= 1000);
    ensures \result == (c <= ((a) + (b)));
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;
    
    return c <= b + a;
}
