/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures ((\result) >= -1 &&
        (\result) <= (((a)) + ((b))) &&
        ((\result) == -1 ==> (((a)) + ((b))) % 2 == 1) &&
        ((\result) != -1 ==> (((a)) + ((b))) % 2 == 0) &&
        ((\result) != -1 ==> (\result) == (((a)) + ((b))) / 2));
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    int result;
    unsigned int count;
    unsigned int temp_sum;

    sum = a + b;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    if (temp_sum == 1)
    {
        return -1;
    }

    result = (int)count;
    return result;
}
