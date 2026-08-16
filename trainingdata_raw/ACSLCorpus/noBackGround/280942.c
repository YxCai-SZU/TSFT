/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result == ((((a)) * 3 + ((p))) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int p)
{
    unsigned int sum;
    unsigned int result;
    unsigned int temp_sum;
    unsigned int count;

    sum = a * 3 + p;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == a * 3 + p;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant count == (sum - temp_sum) / 2;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == ((((a)) * 3 + ((p))) / 2);
    return result;
}
