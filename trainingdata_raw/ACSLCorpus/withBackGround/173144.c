#include <stdbool.h>

/*@ predicate condition(integer k, integer x) = 500 * k >= x; */

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result <==> condition(k, x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool result;
    //@ assert condition(k, x) <==> (500 * k >= x);
    result = (500 * k >= x);
    return result;
}
