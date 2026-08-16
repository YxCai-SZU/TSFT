#include <stdbool.h>

/*@
    predicate condition_holds(integer n, integer k) =
        k * 2 <= n + 1;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= k && k <= 100;
    ensures \result == (k * 2 <= n + 1);
*/
bool func(unsigned int n, unsigned int k)
{
    bool result;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    if (k * 2 <= n + 1) {
        //@ assert condition_holds(n, k);
        result = true;
    } else {
        //@ assert !condition_holds(n, k);
        result = false;
    }
    
    //@ assert result == (k * 2 <= n + 1);
    return result;
}
