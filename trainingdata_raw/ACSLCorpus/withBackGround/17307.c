#include <stdbool.h>

/*@
    predicate is_valid_range(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer pass_condition(integer n) = n / 2 + n % 2;

    lemma pass_condition_bound: \forall integer n; 1 <= n <= 100 ==> pass_condition(n) <= n;
*/

/*@
    requires is_valid_range(n, k);
    ensures \result == (k <= n / 2 + n % 2);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool can_pass = false;
    unsigned int pass_condition_val;

    //@ assert n / 2 + n % 2 <= n;
    pass_condition_val = n / 2 + n % 2;

    if (k <= pass_condition_val)
    {
        can_pass = true;
    }

    //@ assert n / 2 <= n;
    //@ assert n % 2 <= 1;
    //@ assert n / 2 + n % 2 <= n;
    //@ assert can_pass == (k <= n / 2 + n % 2);

    return can_pass;
}
