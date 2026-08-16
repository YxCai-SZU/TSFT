#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer k) =
        1 <= n && n <= 1000000000000000000 &&
        1 <= k && k <= 1000000000000000000;

    predicate diff_satisfies(integer n, integer k, integer diff) =
        (n % k == 0 ==> diff == 0) &&
        (n % k != 0 ==> diff == 1);
*/

/*@
    requires is_valid_params(n, k);
    ensures diff_satisfies(n, k, \result);
    assigns \nothing;
*/
uint64_t distribute_crackers(uint64_t n, uint64_t k)
{
    uint64_t diff;
    //@ assert is_valid_params(n, k);
    
    if (n % k == 0) {
        diff = 0;
        //@ assert diff == 0;
    } else {
        diff = 1;
        //@ assert diff == 1;
    }
    
    //@ assert diff_satisfies(n, k, diff);
    return diff;
}
