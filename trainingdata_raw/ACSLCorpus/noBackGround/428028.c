#include <stdint.h>

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result <= 20000;
    ensures \result == ((x) * (y)) ||
            \result == ((x) * (z)) ||
            \result == ((y) * (z));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t max1;
    uint32_t max2;
    uint32_t xy;
    uint32_t xz;
    uint32_t yz;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert (1 <= (z) <= 100);

    xy = x * y;
    //@ assert xy == ((x) * (y));
    //@ assert xy <= 10000;

    xz = x * z;
    //@ assert xz == ((x) * (z));
    //@ assert xz <= 10000;

    yz = y * z;
    //@ assert yz == ((y) * (z));
    //@ assert yz <= 10000;

    if (xy > xz)
    {
        max1 = xy;
    }
    else
    {
        max1 = xz;
    }

    //@ assert max1 == ((x) * (y)) || max1 == ((x) * (z));

    if (max1 > yz)
    {
        max2 = max1;
    }
    else
    {
        max2 = yz;
    }

    //@ assert max2 <= 20000;
    //@ assert max2 == ((x) * (y)) || max2 == ((x) * (z)) || max2 == ((y) * (z));

    return max2;
}
