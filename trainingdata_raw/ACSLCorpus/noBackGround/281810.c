#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 && ((\result) == (a) - 2 * (b) || (\result) == 0));
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    if (a < 2 * b) {
        //@ assert a < 2 * b;
        return 0;
    }
    //@ assert a >= 2 * b;
    return a - 2 * b;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 && ((\result) == (a) - 2 * (b) || (\result) == 0));
*/
int func2(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    if (a < 2 * b) {
        //@ assert a < 2 * b;
        return 0;
    }
    //@ assert a >= 2 * b;
    return a - 2 * b;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 && ((\result) == (a) - 2 * (b) || (\result) == 0));
*/
int func3(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    if (a < 2 * b) {
        //@ assert a < 2 * b;
        return 0;
    } else {
        //@ assert a >= 2 * b;
        return a - 2 * b;
    }
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= 0 && ((\result) == (a) - 2 * (b) || (\result) == 0));
*/
int func4(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    if (a < 2 * b) {
        //@ assert a < 2 * b;
        return 0;
    } else {
        //@ assert a >= 2 * b;
        //@ assert a - 2 * b >= 0;
        return a - 2 * b;
    }
}
