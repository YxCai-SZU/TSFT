#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate condition_holds(integer n, integer m) = 
        is_even(m) && m >= n * 2;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= m && m <= 100;
    ensures \result == true <==> condition_holds(n, m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at scope top
    bool result;

    //@ assert n * 2 <= 200;
    //@ assert m >= n * 2 || m < n * 2;

    if (m % 2 == 0 && m >= n * 2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
