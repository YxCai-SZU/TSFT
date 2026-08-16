#include <stdint.h>

/*@
    predicate valid_inputs(integer r, integer g) =
        0 <= r <= 4000 &&
        0 <= g <= 4000 &&
        r < g;

    logic integer compute_performance(integer r, integer g) =
        g * 2 - r;

    lemma g_bound_lemma:
        \forall integer g; 0 <= g <= 4000 ==> g * 2 <= 8000;
*/

/*@
    requires valid_inputs(r, g);
    ensures \result == compute_performance(r, g);
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    int32_t performance;

    //@ assert 0 <= g <= 4000;
    //@ assert g * 2 <= 8000;

    performance = g * 2 - r;

    //@ assert performance == compute_performance(r, g);
    return performance;
}
