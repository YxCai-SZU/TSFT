#include <stdbool.h>

/*@
    requires 1 <= a && a <= 5000;
    requires 1 <= b && b <= 5000;
    requires 1 <= c && c <= 10000;
    ensures \result == (a + b >= c);
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min_ab;

    min_ab = a;
    if (b < min_ab)
    {
        min_ab = b;
    }

    //@ assert (((min_ab) == (a) || (min_ab) == (b)) &&         (min_ab) <= (a) && (min_ab) <= (b));

    return c <= min_ab + b || c <= a + min_ab;
}
