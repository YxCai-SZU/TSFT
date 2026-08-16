/*@
    predicate valid_params(integer n, integer a, integer b) =
        2 <= n && n <= 100 &&
        1 <= a && a < b && b <= n &&
        a != b;

    logic integer interval(integer a, integer b) = b - a - 1;

    lemma interval_nonnegative: \forall integer a, b; a < b ==> interval(a, b) >= 0;
    lemma interval_bound: \forall integer n, a, b; valid_params(n, a, b) ==> interval(a, b) <= n - 2;
*/

#include <stdbool.h>

/*@
    requires valid_params(n, a, b);
    ensures \result == (interval(a, b) % 2 == 0);
*/
bool func(int n, int a, int b)
{
    int interval = b - a - 1;
    bool is_even = false;
    int temp_interval = interval;

    /*@
        loop invariant 0 <= temp_interval <= interval;
        loop invariant (interval(a, b) % 2) == (temp_interval % 2);
        loop assigns temp_interval;
    */
    while (temp_interval >= 2)
    {
        temp_interval -= 2;
    }

    if (temp_interval == 0)
    {
        is_even = true;
    }

    return is_even;
}
