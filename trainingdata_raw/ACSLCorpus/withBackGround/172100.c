#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate(integer a, integer b, integer c) =
        10 * c + a + b + 1;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result >= calculate(a, b, c);
    ensures \result < 10 * (c + 1) + a + b + 1;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    ans = 10 * c + a + b + 1;
    //@ assert ans == calculate(a, b, c);
    //@ assert ans >= calculate(a, b, c);
    //@ assert ans < 10 * (c + 1) + a + b + 1;
    return ans;
}
