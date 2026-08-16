#include <stdbool.h>

/*@
    requires 2 <= n <= 100;
    requires 1 <= a < b <= n;
    ensures \result == (a <= (b - 1) || b <= (n - 1) || a <= (n - 1));
*/
bool func(int n, int a, int b)
{
    bool result;

    //@ assert ((a) <= (b) - 1) || ((b) <= (n) - 1) || ((a) <= (n) - 1);
    if (a <= (b - 1) || b <= (n - 1) || a <= (n - 1))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
