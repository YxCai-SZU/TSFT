#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> (a - d) * (b - c) > 0;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int product;
    bool result;

    diff1 = a - d;
    diff2 = b - c;

    //@ assert diff1 >= -10000 && diff1 <= 10000;
    //@ assert diff2 >= -10000 && diff2 <= 10000;
    //@ assert diff1 * diff2 >= -1000000000 && diff1 * diff2 <= 1000000000;

    product = diff1 * diff2;

    if (product > 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
