#include <stdint.h>

/*@
    predicate valid_input(integer R, integer G) =
        0 <= R && R <= 400 &&
        0 <= G && G <= 400 &&
        R <= G &&
        G - R <= 100;

    logic integer compute_ans(integer R, integer G) = 2 * G - R;

    lemma ans_nonnegative:
        \forall integer R, G;
        valid_input(R, G) ==> compute_ans(R, G) >= 0;
*/

/*@
    requires valid_input(R, G);
    ensures \result >= 0;
    ensures \result == compute_ans(R, G);
*/
int64_t func(int64_t R, int64_t G)
{
    int64_t ans;
    //@ assert valid_input(R, G);
    ans = 2 * G - R;
    //@ assert ans == compute_ans(R, G);
    //@ assert ans >= 0;
    return ans;
}
