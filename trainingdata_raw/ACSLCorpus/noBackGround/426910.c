#include <stdbool.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (a) <= 100 && (b) <= 100);
    ensures \result == ((a) - (b) + 1);
    ensures \result >= -99 && \result <= 100;
*/
int func(int a, int b)
{
    int res;
    //@ assert ((a) >= 1 && (b) >= 1 && (a) <= 100 && (b) <= 100);
    res = a - b + 1;
    //@ assert res == ((a) - (b) + 1);
    //@ assert res >= -99 && res <= 100;
    return res;
}
