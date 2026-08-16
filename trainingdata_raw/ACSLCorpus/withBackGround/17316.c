#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
*/

/*@
    lemma n_minus_m_nonnegative:
        \forall integer n, m; valid_range(n, m) ==> n - m >= 0;
*/

/*@
    requires valid_range(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    //@ assert valid_range(n, m);
    //@ assert n - m >= 0;
    return n == m;
}

/*@
    requires valid_range(n, m);
    ensures \result == true;
    assigns \nothing;
*/
bool func2(int n, int m)
{
    //@ assert valid_range(n, m);
    //@ assert n - m >= 0;
    return true;
}

/*@
    requires valid_range(n, m);
    ensures \result == false;
    assigns \nothing;
*/
bool func3(int n, int m)
{
    //@ assert valid_range(n, m);
    //@ assert n - m >= 0;
    return false;
}
