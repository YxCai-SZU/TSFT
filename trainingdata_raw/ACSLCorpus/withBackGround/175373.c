/*@
    predicate valid_params(integer H, integer W, integer h, integer w) =
        1 <= H <= 20 &&
        1 <= W <= 20 &&
        1 <= h <= H &&
        1 <= w <= W;
*/

/*@
    logic integer compute_result(integer H, integer W, integer h, integer w) =
        (H - h) * (W - w);
*/

/*@
    lemma arithmetic_bounds:
        \forall integer H, W, h, w;
        valid_params(H, W, h, w) ==>
        H - h >= 0 && W - w >= 0 &&
        compute_result(H, W, h, w) <= (20 - 1) * (20 - 1);
*/

/*@
    requires valid_params(H, W, h, w);
    ensures \result == compute_result(H, W, h, w);
    assigns \nothing;
*/
int func(int H, int W, int h, int w)
{
    //@ assert H - h >= 0;
    //@ assert W - w >= 0;
    //@ assert (H - h) * (W - w) <= (20 - 1) * (20 - 1);
    
    int result;
    result = (H - h) * (W - w);
    
    return result;
}
