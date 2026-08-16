/*@
    predicate valid_range(integer x) = 3 <= x <= 20;

    lemma sum_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> a + b >= 0;

    lemma expr_nonnegative:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> 
            (a > b ? a : b) * 2 - 1 >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
*/
int func(int a, int b) {
    int max;
    int result;

    max = (a > b) ? a : b;
    result = max * 2 - 1;

    if (a == b) {
        //@ assert result == 2 * a - 1 && result == 2 * b - 1;
        //@ assert result >= 0;
        return result;
    } else if (a == max) {
        //@ assert a + b >= 0;
        return a + b;
    } else {
        //@ assert result >= 0;
        return result;
    }
}
