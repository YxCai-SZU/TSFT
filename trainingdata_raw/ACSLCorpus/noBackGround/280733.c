#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (((a) * (c)) <= ((b) * (d)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    //@ assert ((a) * (c)) <= 10000;
    //@ assert ((b) * (d)) <= 10000;
    return (a * c) <= (b * d);
}
