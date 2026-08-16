/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer expected_result(integer a, integer b, integer c) =
        a < b + c ? a - b : 0;

    lemma result_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        expected_result(a, b, c) >= 0 &&
        expected_result(a, b, c) <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == expected_result(a, b, c);
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert valid_input(a, b, c);
    
    if (a < b + c) {
        result = a - b;
    } else {
        result = 0;
    }
    
    //@ assert result == expected_result(a, b, c);
    
    if (result > c) {
        //@ assert result > c;
        return c;
    } else {
        //@ assert result <= c;
        return result;
    }
}
