#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;
    
    predicate possible_result(integer n, integer m, integer r) =
        r == n + m || r == n - m || r == -n + m;
*/

/*@
    requires valid_range(n, m);
    ensures \result >= 0;
    ensures \result <= 201;
    ensures possible_result(n, m, \result);
*/
int func(int n, int m)
{
    int x;
    int result;
    
    //@ assert valid_range(n, m);
    
    if (n + m >= -n + m)
    {
        x = n + m;
    }
    else
    {
        x = -n + m;
    }
    
    //@ assert x == n + m || x == -n + m;
    
    if (x >= n - m)
    {
        result = x;
    }
    else
    {
        result = n - m;
    }
    
    //@ assert result >= 0;
    //@ assert result == n + m || result == n - m || result == -n + m;
    
    return result;
}
