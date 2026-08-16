#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer k) =
        a % k == 0 || b % k == 0 || a / k < b / k;
*/

/*@
    requires 1 <= a <= b <= 1000;
    requires 1 <= k <= 1000;
    ensures \result == (a % k == 0 || b % k == 0 || a / k < b / k);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert 1 <= a <= b <= 1000;
    //@ assert 1 <= k <= 1000;
    
    if (a % k == 0 || b % k == 0 || a / k < b / k)
    {
        //@ assert a % k == 0 || b % k == 0 || a / k < b / k;
        result = true;
    }
    else
    {
        //@ assert !(a % k == 0 || b % k == 0 || a / k < b / k);
        result = false;
    }
    
    return result;
}
