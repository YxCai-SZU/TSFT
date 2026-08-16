#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> (((x) / 100 >= 5) || ((x) / 100 >= 1 && ((x) / 10) % 10 == 5));
    assigns \nothing;
 */
bool func(int x)
{
    int h;
    int m;
    bool result;

    h = x / 100;
    m = (x / 10) % 10;

    if (h >= 5)
    {
        result = true;
    }
    else if (h >= 1 && m == 5)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
