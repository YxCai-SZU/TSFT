#include <stdbool.h>

/*@
    predicate is_prime_candidate(integer x) =
        x == 3 || x == 5 || x == 7;
 */

/*@
    requires 1 <= x <= 9;
    ensures \result <==> is_prime_candidate(x);
    assigns \nothing;
 */
bool func(int x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= x <= 9;
    result = (x == 3 || x == 5 || x == 7);
    return result;
}
