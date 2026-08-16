/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_c(integer a, integer b) = a - 2 * b;

    lemma func_postcondition:
        \forall integer a, b, result;
            valid_range(a) && valid_range(b) &&
            (compute_c(a, b) > 0 ==> result == compute_c(a, b)) &&
            (compute_c(a, b) <= 0 ==> result == 0) ==>
            result >= 0 &&
            (result == compute_c(a, b) || result == 0);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result == compute_c(a, b) || \result == 0;
*/
int func(int a, int b)
{
    int c;
    int result;

    c = a - 2 * b;
    //@ assert c == compute_c(a, b);

    if (c > 0)
    {
        //@ assert c == compute_c(a, b);
        result = c;
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == compute_c(a, b) || result == 0;
    return result;
}
