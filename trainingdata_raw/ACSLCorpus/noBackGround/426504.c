#include <limits.h>

/*@
    requires INT_MIN <= x <= INT_MAX;
    requires INT_MIN <= y <= INT_MAX;
    requires INT_MIN <= z <= INT_MAX;
    ensures ((x) == (y) && (y) == (z)) ==> \result == 3;
    ensures ((x) == (y) || (y) == (z) || (x) == (z)) ==> \result >= 2;
    ensures \result <= 3;
    ensures \result >= 0;
*/
int test_three_equal(int x, int y, int z)
{
    int ret;

    //@ assert INT_MIN <= x <= INT_MAX;
    //@ assert INT_MIN <= y <= INT_MAX;
    //@ assert INT_MIN <= z <= INT_MAX;

    if (x == y && y == z)
    {
        //@ assert ((x) == (y) && (y) == (z));
        ret = 3;
    }
    else if (x == y || y == z || x == z)
    {
        //@ assert ((x) == (y) || (y) == (z) || (x) == (z));
        ret = 2;
    }
    else
    {
        //@ assert ((x) != (y) && (y) != (z) && (x) != (z));
        ret = 0;
    }

    //@ assert ret <= 3;
    //@ assert ret >= 0;
    return ret;
}
