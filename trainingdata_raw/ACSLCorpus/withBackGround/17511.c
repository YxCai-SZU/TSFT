#include <limits.h>

/*@
    predicate valid_range(integer a) = -32 <= a <= 32;
    predicate product_in_range(integer a, integer b) = -1024 <= a * b <= 1024;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert product_in_range(a, b);

    ans = a * b;
    return ans;
}
