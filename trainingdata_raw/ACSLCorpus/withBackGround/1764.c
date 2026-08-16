#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 3 <= n <= 100;
    logic integer expected_result(integer n) = 180 * (n - 2);
*/

/*@
    requires valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert valid_range(n);
    //@ assert expected_result(n) == 180 * (n - 2);
    
    res = 180 * (n - 2);
    
    //@ assert res == expected_result(n);
    return res;
}
