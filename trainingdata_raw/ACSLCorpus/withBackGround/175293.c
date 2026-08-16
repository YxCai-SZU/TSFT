/*@
    predicate valid_range(integer a, integer b) =
        2 <= a <= 100 && 2 <= b <= 100;
    
    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);
    
    lemma subtraction_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= a - 1 <= 99 && 1 <= b - 1 <= 99;
    
    lemma multiplication_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> (a - 1) * (b - 1) <= 9801;
*/

/*@
    requires valid_range(A, B);
    ensures \result == compute_result(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    // Variable declarations at top
    int result;
    
    //@ assert A > 1;
    //@ assert B > 1;
    //@ assert A <= 100;
    //@ assert B <= 100;
    //@ assert A - 1 <= 99;
    //@ assert B - 1 <= 99;
    //@ assert (A - 1) * (B - 1) <= 9801;
    
    result = (A - 1) * (B - 1);
    return result;
}
