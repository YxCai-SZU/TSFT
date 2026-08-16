/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
int func(int a, int b, int h)
{
    int sum_val;
    int result;
    int temp_sum;
    int count;

    //@ assert 2 <= a + b <= 200;
    //@ assert 2 <= (a + b) * h <= 20000;

    sum_val = (a + b) * h;
    result = 0;
    temp_sum = sum_val;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum_val;
        loop invariant 0 <= count <= sum_val / 2;
        loop invariant sum_val == (a + b) * h;
        loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
        loop invariant temp_sum + 2 * count == sum_val;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    return result;
}
