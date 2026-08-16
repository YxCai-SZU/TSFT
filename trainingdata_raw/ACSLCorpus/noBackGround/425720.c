#include <stdbool.h>

/*@
    requires \true;
    ensures \result >= 0 && \result <= 3;
    ensures \result == 3 ==> ((x) == (y) && (y) == (z));
    ensures \result == 2 ==> ((x) == (y) || (x) == (z) || (y) == (z));
    ensures \result == 0 ==> ((x) != (y) && (x) != (z) && (y) != (z));
    assigns \nothing;
*/
int test_three_equal(int x, int y, int z)
{
    int ret;

    //@ assert \true;
    if (x == y && y == z)
    {
        //@ assert ((x) == (y) && (y) == (z));
        ret = 3;
    }
    else if (x == y || y == z || x == z)
    {
        //@ assert ((x) == (y) || (x) == (z) || (y) == (z));
        ret = 2;
    }
    else
    {
        //@ assert ((x) != (y) && (x) != (z) && (y) != (z));
        ret = 0;
    }

    //@ assert ret >= 0 && ret <= 3;
    return ret;
}
