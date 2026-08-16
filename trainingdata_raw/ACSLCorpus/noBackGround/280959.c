#include <stdbool.h>

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result == (x * y <= 1000);
    assigns \nothing;
*/
bool bound_check(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert 0 <= x <= 8 && 0 <= y <= 8;
    //@ assert ((x) * (y)) <= 64;
    
    return x * y <= 1000;
}
