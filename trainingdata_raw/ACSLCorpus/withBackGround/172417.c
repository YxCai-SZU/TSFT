/*@
    predicate valid_range(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer division_result(integer n, integer k) = n / k;

    lemma division_property:
        \forall integer n, k;
        valid_range(n, k) ==>
        (division_result(n, k) == 0) || (division_result(n, k) != 0);
*/

#include <stdbool.h>

/*@
    requires valid_range(n, k);
    ensures \result == (n / k == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int division;

    //@ assert valid_range(n, k);
    
    division = n / k;
    //@ assert division == n / k;
    
    result = (division == 0);
    //@ assert result == (n / k == 0);
    
    return result;
}
