#include <stdbool.h>

/*@ predicate condition(integer n, integer k) = n >= k * 2 - 1; */

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (n >= k * 2 - 1);
    assigns \nothing;
*/
bool func(int n, int k)
{
    bool result;
    
    //@ assert n >= k * 2 - 1 ==> n >= k * 2 - 1;
    
    result = (n >= k * 2 - 1);
    return result;
}
