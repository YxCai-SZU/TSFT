#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        0 <= (d) && (d) <= 100);
    ensures \result == (((a) * (c)) < ((b) * (d)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100 &&         0 <= (d) && (d) <= 100);
    //@ assert 0 <= ((a) * (c)) && ((a) * (c)) <= 10000;
    //@ assert 0 <= ((b) * (d)) && ((b) * (d)) <= 10000;
    return (a * c) < (b * d);
}
