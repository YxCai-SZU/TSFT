#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
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

    // First comparison and swap
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    // Second comparison and swap
    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }

    // Third comparison and swap
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert ((x) <= (y) && (y) <= (z));

    // Check the triangle condition
    if (x + y == z || x + z == y || y + z == x)
    {
        //@ assert x + y == z || x + z == y || y + z == x;
        return true;
    }
    else
    {
        //@ assert !(x + y == z || x + z == y || y + z == x);
        return false;
    }
}
