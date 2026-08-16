/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    
    logic integer compute_result(integer n) = (n - 2) * 180;
    
    lemma no_underflow: \forall integer n; valid_n(n) ==> n - 2 >= 1;
    lemma no_overflow: \forall integer n; valid_n(n) ==> (n - 2) * 180 <= (100 - 2) * 180;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top
    int result;
    
    //@ assert n >= 3 && n <= 100;
    //@ assert n - 2 >= 1;
    //@ assert (n - 2) * 180 <= (100 - 2) * 180;
    
    result = (n - 2) * 180;
    
    //@ assert result == compute_result(n);
    return result;
}
