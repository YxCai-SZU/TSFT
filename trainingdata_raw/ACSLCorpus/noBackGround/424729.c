#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == (((a) * (b)) <= ((c) * (d)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    //@ assert (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    return a * b <= c * d;
}
