/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
    ensures \result == ((A) * 3 + (P)) / 2;
*/
int func(int A, int P)
{
    int sum;
    int result;
    int temp_sum;
    int count;
    
    sum = A * 3 + P;
    result = 0;
    temp_sum = sum;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == ((A) * 3 + (P));
        loop invariant result == 0;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant sum % 2 == temp_sum % 2;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert result == (sum - temp_sum) / 2;
    
    return result;
}
