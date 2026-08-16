/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_valid_input(integer a, integer b) = 1 <= a <= 20 && 1 <= b <= 20;
    logic integer safe_product(integer a, integer b) = a * b;
    lemma product_bounds: \forall integer a, b; is_small(a) && is_small(b) ==> 1 <= safe_product(a, b) <= 81;
*/

/*@
    requires is_valid_input(A, B);
    ensures (A <= 9 && B <= 9 ==> \result == (int)(A * B)) &&
            (A > 9 || B > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(unsigned int A, unsigned int B)
{
    int result;
    //@ assert is_valid_input(A, B);
    
    if (A <= 9 && B <= 9) {
        //@ assert is_small(A) && is_small(B);
        //@ assert 1 <= A * B <= 81;
        result = (int)(A * B);
    } else {
        //@ assert A > 9 || B > 9;
        result = -1;
    }
    
    return result;
}
