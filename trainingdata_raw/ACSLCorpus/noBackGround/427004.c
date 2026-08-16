#include <limits.h>

/*@
    requires ((x) >= 0 && (x) <= 10) && ((y) >= 0 && (y) <= 10) && ((z) >= 0 && (z) <= 10);
    ensures \result == ((x) * (y) * (z));
    ensures ((x) * (y) * (z) >= 0 && (x) * (y) * (z) <= 1000);
*/
int func(int x, int y, int z)
{
    //@ assert ((x) >= 0 && (x) <= 10);
    //@ assert ((y) >= 0 && (y) <= 10);
    //@ assert ((z) >= 0 && (z) <= 10);
    //@ assert x * y >= 0 && x * y <= 100;
    //@ assert x * y * z >= 0 && x * y * z <= 1000;
    return x * y * z;
}
