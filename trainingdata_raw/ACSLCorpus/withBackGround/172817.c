#include <limits.h>

/*@
    predicate valid_radius(integer r) = r >= 0 && 2 * 31416 * r <= INT_MAX;
    predicate valid_perimeter(integer p) = p >= 0;
*/

/*@
    requires valid_radius(r);
    ensures valid_perimeter(\result);
    ensures \result == 2 * 31416 * r;
*/
int perimeter_circle(int r)
{
    int pi_approx;
    int two_pi;
    int perimeter;

    pi_approx = 31416;
    two_pi = 2 * pi_approx;
    perimeter = two_pi * r;

    //@ assert perimeter == 2 * 31416 * r;

    return perimeter;
}
