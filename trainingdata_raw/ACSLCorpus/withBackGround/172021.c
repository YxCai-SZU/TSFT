#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer compute_result(integer a, integer b) =
        (a < 10 && b < 10) ? a * b : -1;

    lemma result_correct:
        \forall integer a, b, r;
        valid_input(a, b) && r == compute_result(a, b) ==>
            (a < 10 && b < 10 ==> r == a * b) &&
            (a >= 10 || b >= 10 ==> r == -1);
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t ans;
    //@ assert valid_input(a, b);
    
    if (a >= 10 || b >= 10) {
        ans = -1;
        //@ assert ans == -1;
    } else {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert a * b <= 81;
        ans = (int32_t)(a * b);
        //@ assert ans == a * b;
    }
    
    //@ assert ans == compute_result(a, b);
    return ans;
}
