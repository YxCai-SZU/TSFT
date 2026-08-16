/*@
    predicate is_valid_range(integer N) = 1 <= N <= 1000;
    
    logic integer division_by_3(integer N) = N / 3;
    
    lemma division_property:
        \forall integer N; is_valid_range(N) ==> division_by_3(N) >= 0;
*/

/*@
    requires is_valid_range(N);
    ensures \result == division_by_3(N);
    assigns \nothing;
*/
long func(long N)
{
    long result;
    long temp_N;
    long count;
    
    result = 0;
    temp_N = N;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= division_by_3(N);
        loop invariant temp_N == N - 3 * count;
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        //@ assert temp_N >= 3;
        temp_N = temp_N - 3;
        count = count + 1;
    }
    
    result = count;
    
    //@ assert result == division_by_3(N);
    return result;
}
