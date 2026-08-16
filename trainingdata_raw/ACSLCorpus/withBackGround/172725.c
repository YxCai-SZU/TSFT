/*@
    predicate valid_params(integer H, integer W, integer h, integer w) =
        1 <= H <= 20 && 1 <= W <= 20 && 1 <= h <= H && 1 <= w <= W;

    logic integer func_result(integer H, integer W, integer h, integer w) =
        H * W - W * h - H * w + (h * w);

    lemma bounds_lemma:
        \forall integer H, W, h, w;
        valid_params(H, W, h, w) ==>
        H * W <= 400 && W * h <= 400 && H * w <= 400 && h * w <= 400;
*/

/*@
    requires valid_params(H, W, h, w);
    ensures \result == func_result(H, W, h, w);
    assigns \nothing;
*/
int func(int H, int W, int h, int w)
{
    //@ assert H * W <= 400;
    //@ assert W * h <= 400;
    //@ assert H * w <= 400;
    //@ assert h * w <= 400;
    
    return H * W - W * h - H * w + (h * w);
}
