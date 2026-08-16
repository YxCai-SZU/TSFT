/*@
    predicate valid_range(integer a) = 2 <= a && a <= 100;
    
    logic integer compute_result(integer a, integer b) = (a - 1) * (b - 1);
    
    lemma result_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 1 <= compute_result(a, b) <= 9801;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == compute_result(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    
    //@ assert A - 1 >= 1;
    //@ assert B - 1 >= 1;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;
    
    ans = (A - 1) * (B - 1);
    
    //@ assert ans == compute_result(A, B);
    return ans;
}
