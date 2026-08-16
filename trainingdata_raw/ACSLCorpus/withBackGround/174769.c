/*@
    predicate valid_range(integer n) = 2 <= n && n <= 100;

    lemma subtraction_safe: \forall integer N, integer M;
        valid_range(N) && valid_range(M) ==> 
        (N - 1) * (M - 1) <= 100 * 99;
*/

/*@
    requires valid_range(N) && valid_range(M);
    ensures \result == (N - 1) * (M - 1);
    assigns \nothing;
*/
int func(int N, int M)
{
    int res;
    
    //@ assert N > 1 && N <= 100;
    //@ assert M > 1 && M <= 100;
    
    //@ assert (N - 1) * (M - 1) <= 100 * 99;
    
    res = (N - 1) * (M - 1);
    
    //@ assert res == (N - 1) * (M - 1);
    
    return res;
}
