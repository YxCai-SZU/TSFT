/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
    ensures \result == ((a) * 3 + (p)) / 2;
*/
int func(int a, int p)
{
    int sum;
    int result;
    int temp_sum;
    int count;
    
    sum = a * 3 + p;
    result = 0;
    temp_sum = sum;
    count = 0;
    
    /*@
        loop invariant ((temp_sum) + 2 * (count) == (sum) &&
        0 <= (temp_sum) &&
        0 <= (count));
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum = temp_sum - 2;
        count = count + 1;
        //@ assert temp_sum + 2 * count == sum;
    }
    
    //@ assert 2 * count <= sum && sum < 2 * (count + 1);
    result = count;
    return result;
}
