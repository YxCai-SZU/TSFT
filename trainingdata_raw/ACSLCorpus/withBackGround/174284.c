/*@
    predicate is_valid_range(integer N) = 1 <= N <= 1000;
    
    logic integer division_result(integer N) = N / 3;
    
    lemma division_property:
        \forall integer N; is_valid_range(N) ==> division_result(N) == N / 3;
*/

/*@
    requires is_valid_range(N);
    ensures \result == division_result(N);
    assigns \nothing;
*/
int func(int N)
{
    int count;
    int value;
    int is_negative;
    int result;
    
    count = 0;
    value = N;
    is_negative = 0;
    
    if (value < 0)
    {
        value = -value;
        is_negative = 1;
    }
    
    /*@
        loop invariant 0 <= value <= N;
        loop invariant 0 <= count <= N / 3;
        loop invariant value == N - 3 * count;
        loop assigns value, count;
        loop variant value;
    */
    while (value >= 3)
    {
        value -= 3;
        count += 1;
    }
    
    if (is_negative)
    {
        result = -count;
        //@ assert result == division_result(N);
        return result;
    }
    else
    {
        result = count;
        //@ assert result == division_result(N);
        return result;
    }
}
