#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a == b + c || b == c + a || c == a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int x;
    int y;
    int z;
    int temp;

    x = a;
    y = b;
    z = c;

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert ((x) <= (y) && (y) <= (z));

    return x + y == z;
}
