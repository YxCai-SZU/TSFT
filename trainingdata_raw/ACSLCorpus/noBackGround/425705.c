#include <stdbool.h>

/*@
    requires (0 <= (a) <= 0x3FFFFFFF &&
        0 <= (b) <= 0x3FFFFFFF &&
        0 <= (c) <= 0x3FFFFFFF &&
        (a) < 10 &&
        (b) < 10 &&
        (c) < 10);
    ensures \result == (a * b * c >= 9);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (0 <= (a) <= 0x3FFFFFFF &&         0 <= (b) <= 0x3FFFFFFF &&         0 <= (c) <= 0x3FFFFFFF &&         (a) < 10 &&         (b) < 10 &&         (c) < 10);
    //@ assert 0 <= a * b * c <= 729;
    //@ assert a * b * c >= 0;
    //@ assert a * b <= 81;
    
    return a * b * c >= 9;
}
