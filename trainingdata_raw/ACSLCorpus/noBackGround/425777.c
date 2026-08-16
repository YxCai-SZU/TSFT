#include <stdbool.h>

/*@
    requires x <= 10 && y <= 20 && z <= 30;
    ensures \result == (x * y * z <= 5000);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 200;
    //@ assert x * y * z <= 6000;
    return x * y * z <= 5000;
}
