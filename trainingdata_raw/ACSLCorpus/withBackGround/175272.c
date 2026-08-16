/*@
predicate within_bounds(integer w, integer h, integer x, integer y, integer r) =
    0 <= w && w <= 10000 &&
    0 <= h && h <= 10000 &&
    0 <= x && x <= w &&
    0 <= y && y <= h &&
    0 <= r && r <= 10000;

predicate result_condition(integer w, integer h, integer x, integer y, integer r) =
    0 <= x - r && x + r <= w && 0 <= y - r && y + r <= h;

lemma result_implication:
    \forall integer w, h, x, y, r;
    within_bounds(w, h, x, y, r) ==>
    (result_condition(w, h, x, y, r) ==> result_condition(w, h, x, y, r));
*/

/*@
requires within_bounds(w, h, x, y, r);
ensures \result == 1 <==> result_condition(w, h, x, y, r);
assigns \nothing;
*/
int func(int w, int h, int x, int y, int r) {
    int result;
    //@ assert within_bounds(w, h, x, y, r);
    result = (0 <= x - r && x + r <= w && 0 <= y - r && y + r <= h);
    //@ assert result == 1 <==> result_condition(w, h, x, y, r);
    return result;
}
