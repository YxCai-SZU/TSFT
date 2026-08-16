#include <stdbool.h>

/*@
    requires (1 <= (n) && 1 <= (m) && 0 <= (k) && (n) <= 100 && (m) <= 100 && (k) <= (n) * (m));
    ensures \result == (k == n * m || (n == 1 && m >= 2 && k >= 3) || (m == 1 && n >= 2 && k >= 3) || (n >= 2 && m >= 2 && k >= 4));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    // Variable declarations at top of scope
    bool ans;

    //@ assert ((n) * (m)) <= 10000;

    if (k == n * m)
    {
        ans = true;
    }
    else if (n == 1 && m >= 2 && k >= 3)
    {
        ans = true;
    }
    else if (m == 1 && n >= 2 && k >= 3)
    {
        ans = true;
    }
    else if (n >= 2 && m >= 2 && k >= 4)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }

    //@ assert ans == (k == n * m || (n == 1 && m >= 2 && k >= 3) || (m == 1 && n >= 2 && k >= 3) || (n >= 2 && m >= 2 && k >= 4));

    return ans;
}
