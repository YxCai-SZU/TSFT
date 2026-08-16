#include <stdbool.h>

/*@
    predicate both_even(integer n, integer m) =
        n % 2 == 0 && m % 2 == 0;

    predicate both_odd(integer n, integer m) =
        n % 2 != 0 && m % 2 != 0;

    predicate same_parity(integer n, integer m) =
        both_even(n, m) || both_odd(n, m);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == true <==> same_parity(n, m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    bool flag = true;

    //@ assert n % 2 == 0 || n % 2 != 0;
    //@ assert m % 2 == 0 || m % 2 != 0;

    if (n % 2 == 0 && m % 2 != 0)
    {
        flag = false;
    }
    else if (n % 2 != 0 && m % 2 == 0)
    {
        flag = false;
    }

    //@ assert flag == true <==> same_parity(n, m);
    return flag;
}
