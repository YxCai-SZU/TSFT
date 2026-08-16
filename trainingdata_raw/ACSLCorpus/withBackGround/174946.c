/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer target_value(integer A, integer B) = (A + B + 1) / 2;
    
    lemma divisor_constant: \forall integer divisor; divisor == 2 ==> divisor == 2;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == target_value(A, B);
*/
int func(int A, int B)
{
    int sum;
    int result;
    int abs_sum;
    int divisor;
    
    sum = A + B + 1;
    result = 0;
    abs_sum = (sum < 0) ? -sum : sum;
    divisor = 2;
    
    /*@
        loop invariant 0 <= abs_sum;
        loop invariant result <= target_value(A, B);
        loop invariant abs_sum == ((sum < 0) ? -(sum + 2 * result) : (sum - 2 * result));
        loop invariant valid_range(A) && valid_range(B);
        loop invariant divisor == 2;
        loop assigns abs_sum, result;
    */
    while (abs_sum >= divisor)
    {
        //@ assert divisor == 2;
        abs_sum -= divisor;
        result += 1;
    }
    
    if (sum < 0)
    {
        result = -result;
    }
    
    //@ assert divisor == 2;
    return result;
}
