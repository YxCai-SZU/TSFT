#include <limits.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer func_result(integer n, integer m) =
        (n == 1 && m == 1) || (n > 1 && m == 1) || (n == 1 && m > 1) ? 1 : 2;

    lemma result_bounds:
        \forall integer n, m;
        valid_range(n, m) ==> 1 <= func_result(n, m) <= n + m;

    lemma result_cases:
        \forall integer n, m;
        valid_range(n, m) ==>
            (n == 1 && m == 1 ==> func_result(n, m) == 1) &&
            (n > 1 && m == 1 ==> func_result(n, m) == 1) &&
            (n == 1 && m > 1 ==> func_result(n, m) == 1) &&
            (n > 1 && m > 1 ==> func_result(n, m) == 2);
*/

/*@
    requires valid_range(n, m);
    ensures \result >= 1;
    ensures \result <= n + m;
    ensures n == 1 && m == 1 ==> \result == 1;
    ensures n > 1 && m == 1 ==> \result == 1;
    ensures n == 1 && m > 1 ==> \result == 1;
    ensures n > 1 && m > 1 ==> \result == 2;
*/
int func(int n, int m)
{
    int result;

    //@ assert valid_range(n, m);

    if (n == 1 && m == 1)
    {
        //@ assert n == 1 && m == 1;
        result = 1;
    }
    else if (n > 1 && m == 1)
    {
        //@ assert n > 1 && m == 1;
        result = 1;
    }
    else if (n == 1 && m > 1)
    {
        //@ assert n == 1 && m > 1;
        result = 1;
    }
    else
    {
        //@ assert n > 1 && m > 1;
        //@ assert 2 >= 1;
        //@ assert 2 <= n + m;
        result = 2;
    }

    //@ assert result >= 1;
    //@ assert result <= n + m;
    return result;
}
