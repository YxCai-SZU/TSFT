#include <limits.h>

/*@
    predicate non_overflow(integer l, integer b) =
        l * l <= INT_MAX &&
        b * b <= INT_MAX &&
        l * l + b * b <= INT_MAX;
*/

/*@
    logic integer diagonal_squared(integer l, integer b) = l * l + b * b;
*/

/*@
    requires l >= 0 && b >= 0;
    requires non_overflow(l, b);
    ensures \result == diagonal_squared(l, b);
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b)
{
    int lsquared;
    int bsquared;
    int sumofsquares;

    //@ assert l * l <= INT_MAX;
    //@ assert b * b <= INT_MAX;
    //@ assert l * l + b * b <= INT_MAX;

    lsquared = l * l;
    bsquared = b * b;
    sumofsquares = lsquared + bsquared;

    return sumofsquares;
}
