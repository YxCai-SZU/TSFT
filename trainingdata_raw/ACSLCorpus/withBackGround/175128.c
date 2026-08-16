#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer compute_res(integer n, integer r) =
        n < 10 ? 100 * (10 - n) + r : r;

    lemma bounds_lemma:
        \forall integer n; 1 <= n <= 100 ==>
            (10 - n) >= -90 && (10 - n) <= 9;
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_res(n, r);
    assigns \nothing;
*/
int func(int n, int r)
{
    int res;
    
    //@ assert 1 <= n <= 100 && 0 <= r <= 4111;
    
    if (n < 10) {
        //@ assert (10 - n) >= 1 && (10 - n) <= 9;
        //@ assert 100 * (10 - n) >= 100 && 100 * (10 - n) <= 900;
        //@ assert 0 <= 100 * (10 - n) + r <= 5011;
        res = 100 * (10 - n) + r;
    } else {
        res = r;
    }
    
    //@ assert res == compute_res(n, r);
    return res;
}
