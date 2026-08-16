#include <stddef.h>

/*@
    predicate valid_params(integer H, integer W, integer h, integer w) =
        1 <= H && H <= 20 &&
        1 <= W && W <= 20 &&
        1 <= h && h <= H &&
        1 <= w && w <= W;
*/

/*@
    logic integer compute_ans(integer H, integer W, integer h, integer w) =
        (W - w) * (H - h);
*/

/*@
    lemma ans_bounded:
        \forall integer H, W, h, w;
        valid_params(H, W, h, w) ==>
        compute_ans(H, W, h, w) <= H * W;
*/

/*@
    lemma ans_max_bounded:
        \forall integer H, W, h, w;
        valid_params(H, W, h, w) ==>
        compute_ans(H, W, h, w) <= 400;
*/

/*@
    requires valid_params(H, W, h, w);
    ensures \result <= H * W;
    ensures \result == compute_ans(H, W, h, w);
*/
size_t func(size_t H, size_t W, size_t h, size_t w)
{
    // Variable declarations at top of scope
    size_t ans;

    //@ assert 1 <= H && H <= 20;
    //@ assert 1 <= W && W <= 20;
    //@ assert 1 <= h && h <= H;
    //@ assert 1 <= w && w <= W;
    //@ assert W - w >= 0;
    //@ assert H - h >= 0;
    //@ assert compute_ans(H, W, h, w) <= H * W;
    //@ assert compute_ans(H, W, h, w) <= 400;

    ans = (W - w) * (H - h);
    return ans;
}
