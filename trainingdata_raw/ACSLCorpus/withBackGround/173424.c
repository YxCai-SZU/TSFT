#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;
*/

/*@
    requires valid_range(n, m);
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    //@ assert valid_range(n, m);
    if (n == m) {
        result = 1;
    } else {
        result = 0;
    }
    //@ assert result == 1 || result == 0;
    return result;
}

/*@
    predicate valid_range1(integer x) =
        1 <= x <= 1000000000;
*/

/*@
    requires valid_range1(x);
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func1(int x)
{
    int result;
    //@ assert valid_range1(x);
    if (x > 1) {
        result = 0;
    } else {
        result = 1;
    }
    //@ assert result == 1 || result == 0;
    return result;
}

/*@
    predicate valid_range2(integer x) =
        1 <= x <= 1000000000;
*/

/*@
    requires valid_range2(x);
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func2(int x)
{
    int result;
    //@ assert valid_range2(x);
    if (x > 1) {
        result = 0;
    } else {
        result = 1;
    }
    //@ assert result == 1 || result == 0;
    return result;
}
