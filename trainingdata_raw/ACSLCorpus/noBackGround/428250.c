#include <stdbool.h>

/*@
    requires 1 <= input <= 100;
    ensures \result == (input >= 30);
*/
bool func(int input)
{
    int x;
    int y;
    bool result;

    x = 30;
    y = input;

    if (x <= y)
    {
        //@ assert x <= y;
        result = true;
    }
    else
    {
        //@ assert y < x;
        result = false;
    }

    return result;
}

/*@
    ensures \result == (((x) <= (y)) ? (x) : (y));
    ensures (x <= y ==> \result == x) && (y <= x ==> \result == y);
*/
int min_int(int x, int y)
{
    int ret;

    if (x <= y)
    {
        //@ assert x <= y;
        ret = x;
    }
    else
    {
        //@ assert y <= x;
        ret = y;
    }

    return ret;
}

/*@
    ensures \result == (((x) >= (y)) ? (x) : (y));
    ensures (x >= y ==> \result == x) && (y >= x ==> \result == y);
*/
int max_int(int x, int y)
{
    int ret;

    if (x >= y)
    {
        //@ assert x >= y;
        ret = x;
    }
    else
    {
        //@ assert y >= x;
        ret = y;
    }

    return ret;
}
