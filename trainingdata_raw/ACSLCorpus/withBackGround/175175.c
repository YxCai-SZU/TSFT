#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer d) =
        1 <= n <= 20 && 1 <= d <= 20;

    logic integer double_d(integer d) = d * 2;
    logic integer double_d_plus_one(integer d) = double_d(d) + 1;

    lemma double_d_bound: \forall integer d; 1 <= d <= 20 ==> double_d(d) <= 40;
    lemma double_d_plus_one_bound: \forall integer d; 1 <= d <= 20 ==> double_d_plus_one(d) <= 41;
*/

/*@
    requires is_valid_params(n, d);
    ensures \result == (n >= double_d_plus_one(d) || (n >= double_d(d) && n % 2 == 1));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert double_d(d) <= 40;
    //@ assert double_d_plus_one(d) <= 41;

    if (n >= d * 2 + 1 || (n >= d * 2 && n % 2 == 1))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
