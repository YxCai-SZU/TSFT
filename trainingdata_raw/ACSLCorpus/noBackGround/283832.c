#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result <==> (a <= x && x <= a + b);
*/
bool func(int a, int b, int x)
{
    bool ans;
    ans = true;

    if (a > x)
    {
        ans = false;
    }
    else if (a + b < x)
    {
        ans = false;
    }

    //@ assert ans <==> (a <= x && x <= a + b);
    return ans;
}
