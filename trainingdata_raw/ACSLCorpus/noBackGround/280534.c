#include <limits.h>

/*@
    requires ((x) >= 0) && ((y) >= 0) && ((z) >= 0);
    requires ((x) + (y) <= INT_MAX - (z));
    ensures \result == x + y + z;
    ensures ((\result) >= 0);
*/
int func(int x, int y, int z) {
    int sum;
    //@ assert x + y <= INT_MAX - z;
    //@ assert x + y >= 0;
    //@ assert x + y <= INT_MAX;
    sum = x + y;
    //@ assert sum + z <= INT_MAX;
    return sum + z;
}
