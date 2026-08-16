#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= k && k <= 100;
    ensures \result <==> ((n) >= (k) * 2 || (n) == (k) * 2 - 1);
*/
bool func(int n, int k)
{
    bool result;
    //@ assert n >= k * 2 || n == k * 2 - 1 <==> ((n) >= (k) * 2 || (n) == (k) * 2 - 1);
    result = (n >= k * 2) || (n == k * 2 - 1);
    return result;
}
