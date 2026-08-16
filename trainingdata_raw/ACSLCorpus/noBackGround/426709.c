#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int z;
    int result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert -10000 <= a * b <= 10000;

    x = a + b;
    y = a - b;
    z = a * b;

    if (x >= y && x >= z)
    {
        result = x;
    }
    else if (y >= x && y >= z)
    {
        result = y;
    }
    else
    {
        result = z;
    }

    //@ assert result == x || result == y || result == z;
    //@ assert result >= x;
    //@ assert result >= y;
    //@ assert result >= z;
    //@ assert result >= ((a) + (b)) && result >= ((a) - (b)) && result >= ((a) * (b));

    return result;
}
