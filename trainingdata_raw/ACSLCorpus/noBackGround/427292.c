#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (
        (a - c) * (b - d) > 0 ||
        (a - c) * (b - d) == 0 ||
        (a - c) * (b - d) < 0
    );
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int product;
    bool result;

    diff1 = a - c;
    diff2 = b - d;

    //@ assert ((a) >= 1 && (a) <= 100 && (c) >= 1 && (c) <= 100 && (diff1) == (a) - (c) && (diff1) >= -99 && (diff1) <= 99);
    //@ assert ((b) >= 1 && (b) <= 100 && (d) >= 1 && (d) <= 100 && (diff2) == (b) - (d) && (diff2) >= -99 && (diff2) <= 99);

    product = diff1 * diff2;

    //@ assert ((a) >= 1 && (a) <= 100 && (b) >= 1 && (b) <= 100 && (c) >= 1 && (c) <= 100 && (d) >= 1 && (d) <= 100 &&         (product) == ((a) - (c)) * ((b) - (d)) && (product) >= -10000 && (product) <= 10000);

    if (product > 0)
    {
        result = true;
    }
    else if (product == 0)
    {
        result = true;
    }
    else
    {
        result = true;
    }

    //@ assert result == true <==> (product > 0 || product == 0 || product < 0);
    return result;
}
