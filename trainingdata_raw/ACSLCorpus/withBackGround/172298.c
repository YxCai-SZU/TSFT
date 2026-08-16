#include <stdbool.h>

/*@
    predicate is_ans(integer a, integer b, integer k, bool ans) =
        ans == true <==> (a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k);
*/

/*@
    requires 1 <= a <= b <= 1000;
    requires 1 <= k <= 1000;
    ensures \result == true <==> (a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    bool ans = false;
    //@ assert ans == false;

    if (a % k == 0 || b % k == 0)
    {
        ans = true;
        //@ assert ans == true;
    }
    else if (b - a >= k)
    {
        ans = true;
        //@ assert ans == true;
    }
    else if (a % k > b % k)
    {
        ans = true;
        //@ assert ans == true;
    }

    //@ assert is_ans(a, b, k, ans);
    return ans;
}
