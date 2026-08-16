/*@
predicate equal(integer x, integer y) = x == y;
predicate less_or_equal(integer x, integer y) = x <= y;

logic integer double_val(integer v) = v * 2;

lemma double_equal:
    \forall integer x, integer y; equal(x, y) ==> double_val(x) == double_val(y);
*/

/*@
requires equal(x, y);
ensures double_val(x) == double_val(y);
assigns \nothing;
*/
void calc_example_8(int x, int y) {
    //@ assert equal(x, y);
    //@ assert double_val(x) == double_val(y);
}

/*@
requires equal(x, y);
requires less_or_equal(y, x);
ensures double_val(y) == double_val(x);
assigns \nothing;
*/
void lemma(int x, int y) {
    //@ assert equal(x, y);
    //@ assert less_or_equal(y, x);
    //@ assert double_val(x) == double_val(y);
}
