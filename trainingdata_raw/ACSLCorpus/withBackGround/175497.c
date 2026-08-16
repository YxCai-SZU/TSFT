#include <stdbool.h>

/*@
    predicate both_small(integer n, integer m) =
        n <= 8 && m <= 8;
 */

/*@
    requires 1 <= n <= 16;
    requires 1 <= m <= 16;
    requires n + m <= 16;
    ensures \result == true <==> (n <= 8 && m <= 8);
    ensures \result == false <==> !(n <= 8 && m <= 8);
 */
bool func(unsigned int n, unsigned int m)
{
    //@ assert 1 <= n <= 16;
    //@ assert 1 <= m <= 16;
    //@ assert n + m <= 16;

    if (n <= 8 && m <= 8)
    {
        //@ assert both_small(n, m);
        return true;
    }
    else
    {
        //@ assert !both_small(n, m);
        return false;
    }
}
