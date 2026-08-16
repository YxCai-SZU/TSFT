#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer compute_result(integer a, integer b) =
        6 - (a + b);

    predicate valid_result(integer r) =
        r == 1 || r == 2 || r == 3;

    lemma sum_bounds: \forall integer a, b; valid_input(a, b) ==> 1 <= a + b <= 6;
    lemma result_bounds: \forall integer a, b; valid_input(a, b) ==> 0 <= compute_result(a, b) <= 5;
    lemma result_valid: \forall integer a, b; valid_input(a, b) ==> valid_result(compute_result(a, b));
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    ensures valid_result(\result);
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ans;
    
    //@ assert 1 <= a + b <= 6;
    ans = 6 - (a + b);
    //@ assert 0 <= ans <= 5;
    
    return ans;
}
