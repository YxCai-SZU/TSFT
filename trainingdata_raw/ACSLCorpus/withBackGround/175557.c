#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    logic integer double_times_three(integer r) = 2 * r * 3;
*/

/*@
    lemma multiplication_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> a * b <= 10000;
*/

/*@
    requires valid_range(r);
    ensures \result == double_times_three(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi;
    int result;

    pi = 3;
    result = 2 * r * pi;

    //@ assert result == 2 * r * 3;
    return result;
}

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func2(int a, int b)
{
    // Variable declarations at scope top
    int ans;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert a * b <= 10000;

    ans = a * b;
    return ans;
}
