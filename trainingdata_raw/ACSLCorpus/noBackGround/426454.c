#include <limits.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) > (m) ? (n) - (m) : 0);
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    result = (n > m) ? (n - m) : 0;
    //@ assert result >= 0;
    //@ assert result <= n;
    //@ assert result == ((n) > (m) ? (n) - (m) : 0);
    return result;
}
