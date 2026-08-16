/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - b * 2;

    lemma result_nonnegative:
        \forall integer a, b;
        valid_range(a, b) && compute_result(a, b) > 0 ==>
        compute_result(a, b) >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    
    if (a > b * 2) {
        result = a - b * 2;
        //@ assert result >= 0;
        return result;
    } else {
        result = 0;
        //@ assert result >= 0;
        return result;
    }
}

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
*/
int func2(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    
    result = a - b * 2;
    
    if (result > 0) {
        //@ assert result >= 0;
        return result;
    } else {
        result = 0;
        //@ assert result >= 0;
        return result;
    }
}
