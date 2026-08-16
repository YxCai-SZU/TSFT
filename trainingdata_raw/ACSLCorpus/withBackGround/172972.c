#include <stdbool.h>

/*@
    predicate condition1(integer n, integer m) =
        n >= m * 2 && (n - m * 2) % 4 == 0;
    
    predicate condition2(integer n, integer m) =
        n < m * 2 && m <= n;
*/

/*@
    requires 1 <= n <= 10000;
    requires 0 <= m <= 1000;
    ensures \result == 1 <==> (condition1(n, m) || condition2(n, m));
*/
bool func(int n, int m)
{
    // Variable declarations at top of scope
    bool result;
    
    if (n >= m * 2)
    {
        if ((n - m * 2) % 4 == 0)
        {
            //@ assert condition1(n, m);
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        if (m <= n)
        {
            //@ assert condition2(n, m);
            result = true;
        }
        else
        {
            result = false;
        }
    }
    
    return result;
}
