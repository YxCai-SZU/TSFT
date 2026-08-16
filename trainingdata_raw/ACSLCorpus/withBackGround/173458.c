#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    logic integer compute_result(integer n, integer i) = n - i;

    lemma result_non_negative:
        \forall integer n, m, i;
        valid_params(n, m) && 0 <= i <= m ==> compute_result(n, i) >= 0;
*/

/*@
    requires valid_params(n, m);
    ensures \result == n - m;
    assigns \nothing;
*/
int func(int n, int m) {
    int result;
    int i;
    
    result = n;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant result == n - i;
        loop invariant valid_params(n, m);
        loop invariant result >= 0;
        loop assigns result, i;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert result == n - i;
        result -= 1;
        i += 1;
        //@ assert result == n - i;
    }
    
    //@ assert result == n - m;
    return result;
}
