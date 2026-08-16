#include <limits.h>

/*@
    predicate in_range(integer n) = 1 <= n <= 10;

    logic integer func_result(integer n) = n + n * n + n * n * n;

    lemma bounds_lemma:
        \forall integer n;
            in_range(n) ==>
            1 + 1 * 1 + 1 * 1 * 1 <= func_result(n) <= 10 + 10 * 10 + 10 * 10 * 10;
*/

/*@
    requires 1 <= n <= 10;
    requires n == (int)n;
    ensures \result == n + n * n + n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 1 <= n && n <= 10;
    
    //@ assert 1 + 1 * 1 + 1 * 1 * 1 <= 10 + 10 * 10 + 10 * 10 * 10;
    
    //@ assert n + n * n + n * n * n <= 10 + 10 * 10 + 10 * 10 * 10;
    
    //@ assert 1 <= n && n <= 10;
    
    return n + n * n + n * n * n;
}
