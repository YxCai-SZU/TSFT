#include <stdbool.h>

/*@
    requires 1 <= n;
    requires 1 <= m;
    requires 0 <= k;
    requires k <= n;
    ensures \result == true <==> (n - k) <= m;
    ensures \result == false <==> (n - k) > m;
*/
bool func(int n, int m, int k)
{
    int t;

    //@ assert 0 <= k && k <= n;
    //@ assert n - k >= 0;
    t = n - k;
    //@ assert t == n - k;
    //@ assert t >= 0;

    if (t <= m)
    {
        //@ assert (n - k) <= m;
        return true;
    }
    else
    {
        //@ assert t > m;
        //@ assert (n - k) > m;
        return false;
    }
}
