#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a + b || \result == a + c + 1 || \result == b + d + 1 || \result == c + d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max1;
    int64_t max2;
    int64_t ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (a + b > c + d)
    {
        max1 = a + b;
    }
    else
    {
        max1 = c + d;
    }

    //@ assert max1 == ((a + b) > (c + d) ? (a + b) : (c + d));

    if (a + c + 1 > b + d + 1)
    {
        max2 = a + c + 1;
    }
    else
    {
        max2 = b + d + 1;
    }

    //@ assert max2 == ((a + c + 1) > (b + d + 1) ? (a + c + 1) : (b + d + 1));

    if (max1 > max2)
    {
        ans = max1;
    }
    else
    {
        ans = max2;
    }

    //@ assert ans == ((max1) > (max2) ? (max1) : (max2));
    //@ assert ans == a + b || ans == a + c + 1 || ans == b + d + 1 || ans == c + d;

    return ans;
}
