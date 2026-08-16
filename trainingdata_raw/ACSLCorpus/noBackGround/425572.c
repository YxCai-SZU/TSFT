#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
bool func(int n, int m)
{
    int x;
    bool result;

    x = n - m;
    
    //@ assert x == n - m;
    
    if (x == 0)
    {
        result = true;
        //@ assert x == 0 ==> n == m;
    }
    else
    {
        result = false;
        //@ assert x != 0 ==> n != m;
    }
    
    //@ assert result == (n == m);
    return result;
}
