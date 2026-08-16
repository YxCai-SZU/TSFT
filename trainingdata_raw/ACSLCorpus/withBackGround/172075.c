/*@
    predicate is_valid_div(integer x, integer y) = y != 0;

    logic integer mydiv(integer x, integer y) = x / y;

    lemma mydiv_lemma:
        \forall integer x, y;
        is_valid_div(x, y) ==> mydiv(x, y) == x / y;
*/

/*@
    requires is_valid_div(20, 10);
    ensures \result == 2;
*/
int test() {
    int result;
    //@ assert mydiv(20, 10) == 2;
    result = 2;
    return result;
}
