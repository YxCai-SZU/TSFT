#include <stdbool.h>

/*@
    requires x <= 1000 && y <= 1000;
    ensures \result == true <==> ((x) * (y) <= 1000000);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    //@ assert x <= 1000 && y <= 1000;
    //@ assert ((x) * (y) <= 1000000);
    return x * y <= 1000000;
}
