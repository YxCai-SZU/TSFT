#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==>
            (x / 100 >= 1 && x / 100 * 100 == x) ||
            (x / 100 >= 1 && x % 100 / 5 == 0) ||
            (x % 100 < 5);
*/
bool func(unsigned long long x)
{
    bool ans;

    //@ assert 1 <= x <= 100000;

    if (x / 100 >= 1 && x / 100 * 100 == x)
    {
        ans = true;
    }
    else if (x / 100 >= 1 && x % 100 / 5 == 0)
    {
        ans = true;
    }
    else if (x % 100 < 5)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }

    //@ assert ans == true <==> (x / 100 >= 1 && x / 100 * 100 == x) || (x / 100 >= 1 && x % 100 / 5 == 0) || (x % 100 < 5);

    return ans;
}
