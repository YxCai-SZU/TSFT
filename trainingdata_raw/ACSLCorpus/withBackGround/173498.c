#include <limits.h>

/*@
    predicate is_valid_range(integer n) =
        n * n * n >= INT_MIN && n * n * n <= INT_MAX;
*/

/*@
    requires is_valid_range(n);
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    // Declare all variables at the top
    int result;

    //@ assert n * n * n >= INT_MIN && n * n * n <= INT_MAX;
    //@ assert n * n >= INT_MIN && n * n <= INT_MAX;
    //@ assert n >= INT_MIN && n <= INT_MAX;

    result = n * n * n;
    return result;
}
