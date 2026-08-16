/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    
    logic integer func_spec(integer n) = 180 * n - 360;
    
    lemma func_lemma:
        \forall integer n; valid_n(n) ==> func_spec(n) == 180 * n - 360;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
long func(long n)
{
    long l;
    long result;
    
    l = 180;
    result = l * n - 360;
    
    //@ assert result == 180 * n - 360;
    
    return result;
}
