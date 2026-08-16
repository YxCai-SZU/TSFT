#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
bool func(int n, int m)
{
    // Variable declarations at scope top
    bool result;
    int diff;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;
    //@ assert m >= 0 && m <= 100;
    
    diff = n - m;
    //@ assert diff >= 0;
    //@ assert diff <= 100;
    
    //@ assert diff == 0 <==> n == m;
    
    result = (n == m);
    return result;
}
