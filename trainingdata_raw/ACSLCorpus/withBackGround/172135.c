#include <stddef.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 100000;

    logic integer base_count(integer x) = (x / 11) * 2;

    lemma ans_bound:
        \forall integer x, ans;
        is_valid_x(x) ==>
        ans == base_count(x) + (x % 11 > 6 ? 2 : 1) ==>
        ans >= base_count(x);
*/

/*@
    requires is_valid_x(x);
    ensures \result >= base_count(x);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t ans;
    size_t x_mod;

    // Declare all variables at the top
    ans = (x / 11) * 2;
    x_mod = x % 11;

    if (x_mod > 6) {
        ans += 2;
        //@ assert ans == base_count(x) + 2;
    } else {
        ans += 1;
        //@ assert ans == base_count(x) + 1;
    }

    return ans;
}
