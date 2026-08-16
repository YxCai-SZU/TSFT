#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;

    logic integer calculate_kakera(integer a, integer p) =
        p + a * 3;

    logic integer calculate_ans(integer a, integer p) =
        calculate_kakera(a, p) / 2;

    lemma ans_bound: \forall integer a, p;
        valid_range(a, p) ==> calculate_ans(a, p) <= calculate_kakera(a, p);

    lemma ans_correct: \forall integer a, p;
        valid_range(a, p) ==> calculate_ans(a, p) == calculate_kakera(a, p) / 2;
*/

/*@
    requires valid_range(a, p);
    ensures \result <= p + a * 3;
    ensures \result == (p + a * 3) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t kakera;
    uint32_t ans;

    kakera = p + a * 3;
    ans = kakera / 2;

    //@ assert ans <= p + a * 3;
    //@ assert ans == (p + a * 3) / 2;

    return ans;
}
