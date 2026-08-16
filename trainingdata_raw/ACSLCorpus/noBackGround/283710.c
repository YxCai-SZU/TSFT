#include <stdbool.h>

/*@
    requires (((a) == 1 && (b) == 2) || ((a) == 2 && (b) == 1) || ((a) == 3 && (b) == 1) ||
        ((a) == 1 && (b) == 3) || ((a) == 3 && (b) == 2));
    ensures \result == (6 - (a) - (b));
    ensures \result == 1 || \result == 2 || \result == 3;
*/
int func(int a, int b)
{
    int res;

    //@ assert (((a) == 1 && (b) == 2) || ((a) == 2 && (b) == 1) || ((a) == 3 && (b) == 1) ||         ((a) == 1 && (b) == 3) || ((a) == 3 && (b) == 2));
    res = 6 - a - b;
    //@ assert res == (6 - (a) - (b));
    //@ assert res == 1 || res == 2 || res == 3;

    return res;
}
