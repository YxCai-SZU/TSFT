#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int diff;
    diff = e - a;

    //@ assert diff == e - a;
    //@ assert diff >= 0;
    //@ assert diff <= 123;
    //@ assert k >= 0;

    if (diff <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
