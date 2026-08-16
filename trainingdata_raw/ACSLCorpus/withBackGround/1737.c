#include <stdint.h>

/*@
    predicate valid_num(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) =
        n * 800 - (n / 15) * 200;

    lemma arithmetic_identity:
        \forall integer n; n * 800 == n * 800;

    lemma division_identity:
        \forall integer n; (n / 15) * 200 == (n / 15) * 200;
*/

/*@
    requires valid_num(num);
    ensures \result == compute_result(num);
    assigns \nothing;
*/
int32_t func(uint32_t num)
{
    int32_t result;

    //@ assert num * 800 == num * 800;
    //@ assert (num / 15) * 200 == (num / 15) * 200;

    result = (int32_t)(num * 800 - (num / 15) * 200);
    return result;
}
