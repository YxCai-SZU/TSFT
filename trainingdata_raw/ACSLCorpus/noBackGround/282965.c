#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures ((\result) == ((n) >= (2 * (((k)) / 2 + 1))));
*/
bool func(unsigned int n, unsigned int k)
{
    bool ans;
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    if (n >= 2 * (k / 2 + 1))
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    //@ assert ans == (n >= 2 * (k / 2 + 1));
    return ans;
}
