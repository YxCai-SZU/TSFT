#include <stdbool.h>

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int temp;

    x = a;
    y = b;
    z = c;

    //@ assert ((x) + (y) + (z)) == ((a) + (b) + (c));

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    //@ assert x <= y;

    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }
    //@ assert y <= z;

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    //@ assert ((x) <= (y) && (y) <= (z));

    //@ assert ((x) + (y) + (z)) == ((a) + (b) + (c));
    return (x + y + z) >= 22;
}
