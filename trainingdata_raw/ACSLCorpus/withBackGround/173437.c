#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer sum_plus_one(integer a, integer b) = a + b + 1 + b;

    lemma sum_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> sum_plus_one(a, b) <= 10000 + 10000 + 1 + 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= sum_plus_one(a, b);
    ensures \result == sum_plus_one(a, b) || \result == c;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int ans;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    //@ assert sum_plus_one(a, b) <= 10000 + 10000 + 1 + 10000;

    if (c < a + b + 1 + b)
    {
        ans = c;
    }
    else
    {
        ans = a + b + 1 + b;
    }

    //@ assert ans <= sum_plus_one(a, b);
    //@ assert ans == sum_plus_one(a, b) || ans == c;
    return ans;
}
