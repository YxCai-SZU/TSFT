#include <stdbool.h>

/*@
    predicate condition(integer n, integer k) =
        (n - 1) / 2 < k - 1;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == ((n - 1) / 2 < k - 1);
*/
bool func(unsigned long n, unsigned long k)
{
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    if ((n - 1) / 2 < k - 1)
    {
        //@ assert (n - 1) / 2 < k - 1;
        result = true;
    }
    else
    {
        //@ assert !((n - 1) / 2 < k - 1);
        result = false;
    }
    
    //@ assert result == ((n - 1) / 2 < k - 1);
    return result;
}
