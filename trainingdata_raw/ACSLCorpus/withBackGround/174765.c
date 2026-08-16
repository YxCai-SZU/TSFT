/*@
    predicate is_valid_param(integer a) = 1 <= a && a <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound:
        \forall integer a, b;
            is_valid_param(a) && is_valid_param(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires is_valid_param(A) && is_valid_param(B) && is_valid_param(C) && is_valid_param(D);
    ensures \result == product(A, B) || \result == product(C, D);
    ensures \result >= product(A, B);
    ensures \result >= product(C, D);
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B, unsigned int C, unsigned int D)
{
    unsigned int res;
    
    //@ assert product(A, B) <= 100000000;
    //@ assert product(C, D) <= 100000000;
    
    if (A * B > C * D)
    {
        //@ assert product(A, B) >= product(C, D);
        res = A * B;
    }
    else
    {
        //@ assert product(C, D) >= product(A, B);
        res = C * D;
    }
    
    return res;
}
