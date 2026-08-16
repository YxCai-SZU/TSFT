/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma product_in_range:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> multiply(a, b) <= 100 * 100;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == multiply(A, B);
*/
int func(int A, int B)
{
    int result;
    
    //@ assert valid_range(A) && valid_range(B);
    //@ assert multiply(A, B) <= 100 * 100;
    
    result = A * B;
    
    //@ assert result == multiply(A, B);
    return result;
}
