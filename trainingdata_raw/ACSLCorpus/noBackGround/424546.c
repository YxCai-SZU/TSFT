/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a + b + c + 1) / 2 + 1;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    unsigned int result;
    unsigned int temp_sum;
    unsigned int count;

    sum = a + b + c + 1;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant count <= (sum - temp_sum) / 2;
        loop assigns temp_sum, count;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    //@ assert temp_sum < 2;
    result = count + 1;

    //@ assert result == (a + b + c + 1) / 2 + 1;
    return result;
}
