#include <stdint.h>

/*@
    predicate valid_params(integer X, integer Y) =
        1 <= X && X <= 100 &&
        1 <= Y && Y <= 100;
*/

/*@
    logic integer product(integer X, integer Y) = X * Y;
*/

/*@
    lemma product_bound:
        \forall integer X, Y;
        valid_params(X, Y) ==> product(X, Y) <= 10000;
*/

/*@
    requires valid_params(X, Y);
    ensures \result == product(X, Y);
    assigns \nothing;
*/
int32_t func(int32_t X, int32_t Y)
{
    //@ assert valid_params(X, Y);
    //@ assert product(X, Y) <= 10000;
    int32_t ans = X * Y;
    return ans;
}
