/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    // Logical function for multiplication
    logic integer safe_mult(integer a, integer b) = a * b;

    // Lemma about multiplication bounds
    lemma mult_bounds: \forall integer a, b;
        valid_range(a) && valid_range(b) && a <= 9 && b <= 9 ==> 
        1 <= safe_mult(a, b) <= 81;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures (a <= 9 && b <= 9 ==> \result == safe_mult(a, b)) &&
            (a > 9 || b > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert valid_range(a) && valid_range(b);
    
    if (a > 9 || b > 9) {
        //@ assert a > 9 || b > 9;
        result = -1;
    } else {
        //@ assert a <= 9 && b <= 9;
        //@ assert 1 <= safe_mult(a, b) <= 81;
        result = a * b;
    }
    
    return result;
}
