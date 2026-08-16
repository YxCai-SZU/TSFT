#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n <= 100 &&
        1 <= a < b <= n;

    logic integer sum_mod2(integer a, integer b) = (a + b) % 2;

    lemma sum_bounds:
        \forall integer n, a, b;
        valid_params(n, a, b) ==>
        a + b <= n + n &&
        a + b >= 1 + 1;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == (sum_mod2(a, b) == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int sum;
    unsigned int mod_result;

    //@ assert valid_params(n, a, b);

    sum = a + b;
    //@ assert sum == a + b;

    //@ assert sum <= n + n;
    //@ assert sum >= 1 + 1;

    mod_result = sum % 2;
    //@ assert mod_result == sum_mod2(a, b);

    if (mod_result == 0) {
        result = true;
        //@ assert result == (sum_mod2(a, b) == 0);
    } else {
        result = false;
        //@ assert result == (sum_mod2(a, b) == 0);
    }

    return result;
}
