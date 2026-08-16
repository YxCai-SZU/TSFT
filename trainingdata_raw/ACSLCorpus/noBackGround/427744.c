#include <limits.h>

/*@
    requires (0 <= (x) && (x) <= 10000) && (0 <= (y) && (y) <= 10000) && (0 <= (z) && (z) <= 10000);
    ensures \result >= 0;
    ensures \result == ((x) + (y)) || \result == ((y) + (z)) || \result == ((z) + (x));
*/
int func(int x, int y, int z)
{
    int max;
    int xy_sum;
    int yz_sum;
    int zx_sum;

    xy_sum = x + y;
    yz_sum = y + z;
    zx_sum = z + x;

    //@ assert ((xy_sum) >= 0) && ((yz_sum) >= 0) && ((zx_sum) >= 0);

    if (xy_sum > yz_sum)
    {
        if (xy_sum > zx_sum)
        {
            max = xy_sum;
        }
        else
        {
            max = zx_sum;
        }
    }
    else
    {
        if (yz_sum > zx_sum)
        {
            max = yz_sum;
        }
        else
        {
            max = zx_sum;
        }
    }

    //@ assert max >= 0;
    return max;
}
