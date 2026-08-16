/*@
    predicate valid_input(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer result_val(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma bounds_lemma:
        \forall integer a, b;
        valid_input(a, b) ==>
        1 <= a - 1 && a - 1 <= 99 &&
        1 <= b - 1 && b - 1 <= 99 &&
        1 <= result_val(a, b) && result_val(a, b) <= 9801;
*/

/*@
    requires valid_input(a, b);
    ensures \result == result_val(a, b);
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert 1 <= a - 1 && a - 1 <= 99;
    //@ assert 1 <= b - 1 && b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) && (a - 1) * (b - 1) <= 9801;

    result = (a - 1) * (b - 1);
    return result;
}
