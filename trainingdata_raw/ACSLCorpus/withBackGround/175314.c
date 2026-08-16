#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer compute_result(integer r) = r * 2 * 3;

    lemma test_lemma: \forall integer r; valid_range(r) ==> compute_result(r) == r * 2 * 3;
*/

/*@
    requires valid_range(r);
    ensures \result == compute_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int res;

    //@ assert valid_range(r);
    
    pi = 3;
    res = r * 2 * pi;
    
    //@ assert res == r * 2 * 3;
    
    return res;
}
