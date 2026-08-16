#include <limits.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
*/

/*@
    logic integer expected_result(integer n) = n * 2 * 3;
*/

/*@
    lemma result_correctness:
        \forall integer n; valid_n(n) ==> expected_result(n) == n * 6;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int i;
    
    result = 1;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant result == 1;
        loop assigns i;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        i = i + 1;
    }
    
    //@ assert valid_n(n);
    result = n * 2 * 3;
    
    //@ assert result == expected_result(n);
    return result;
}
