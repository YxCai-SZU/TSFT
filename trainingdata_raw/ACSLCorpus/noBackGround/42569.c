#include <limits.h>

/*@
    requires (1 <= (x) <= 100 && 1 <= (y) <= 100 && 1 <= (z) <= 100);
    ensures \result == x * y + z;
    ensures \result <= 10100;
*/
int nonlinear_arithmetic_example(int x, int y, int z)
{
    //@ assert (1 <= (x) <= 100 && 1 <= (y) <= 100 && 1 <= (z) <= 100);
    //@ assert x * y <= 10000;
    //@ assert x * y + z <= 10100;
    return x * y + z;
}
