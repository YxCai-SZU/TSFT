#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;

    logic integer compute_result(integer n, integer m) =
        n * n - m;

    lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    int i;
    int result;

    //@ ghost int original_n = n;
    //@ ghost int original_m = m;

    i = 0;

    /*@
        loop invariant 0 <= i <= original_n;
        loop invariant is_valid_params(original_n, original_m);
        loop assigns i;
        loop variant original_n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    //@ assert original_n * original_n <= 10000;

    result = n * n - m;
    return result;
}
