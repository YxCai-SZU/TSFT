/*@
    predicate valid_range(integer N) = 1 <= N <= 100;
    
    logic integer half(integer N) = N / 2;
    logic integer remainder(integer N) = N % 2;
    logic integer expected_result(integer N) = half(N) + remainder(N);
    
    lemma half_remainder_relation: \forall integer N; valid_range(N) ==> 
        N == 2 * half(N) + remainder(N);
*/

/*@
    requires valid_range(N);
    ensures \result == expected_result(N);
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int half_N;
    int temp_N;
    int remainder;
    
    result = 0;
    half_N = 0;
    temp_N = N;
    
    /*@
        loop invariant 0 <= half_N <= half(N);
        loop invariant 0 <= temp_N;
        loop invariant temp_N + 2 * half_N == N;
        loop assigns half_N, temp_N;
        loop variant temp_N;
    */
    while (temp_N >= 2)
    {
        //@ assert temp_N >= 2;
        half_N = half_N + 1;
        temp_N = temp_N - 2;
        //@ assert temp_N + 2 * half_N == N;
    }
    
    //@ assert temp_N == 0 || temp_N == 1;
    if (temp_N == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }
    
    //@ assert remainder == remainder(N);
    result = half_N + remainder;
    
    //@ assert result == expected_result(N);
    return result;
}
