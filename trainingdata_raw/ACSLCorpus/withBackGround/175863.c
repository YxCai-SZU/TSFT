/*@
    predicate valid_range(integer N, integer M) =
        2 <= N <= 100 && 2 <= M <= 100;
    
    logic integer result_value(integer N, integer M) =
        (N - 1) * (M - 1);
    
    lemma arithmetic_bounds:
        \forall integer N, M;
        valid_range(N, M) ==>
        (N - 1) >= 1 && (M - 1) >= 1 &&
        (N - 1) <= 99 && (M - 1) <= 99 &&
        result_value(N, M) <= 9801;
*/

/*@
    requires valid_range(N, M);
    ensures \result == result_value(N, M);
    assigns \nothing;
*/
long func(long N, long M)
{
    long result;
    
    //@ assert N - 1 >= 1;
    //@ assert M - 1 >= 1;
    //@ assert (N - 1) <= 99;
    //@ assert (M - 1) <= 99;
    //@ assert (N - 1) * (M - 1) <= 9801;
    
    result = (N - 1) * (M - 1);
    
    //@ assert result == result_value(N, M);
    return result;
}
