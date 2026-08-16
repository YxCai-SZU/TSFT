/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a * 10 + b + c) ||
            \result == (a + b * 10 + c) ||
            \result == (a + b + c * 10);
*/
int func(int a, int b, int c)
{
    int max_sum[3];
    int max_value;
    int i;

    max_sum[0] = a * 10 + b + c;
    max_sum[1] = a + b * 10 + c;
    max_sum[2] = a + b + c * 10;
    max_value = max_sum[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant max_sum[0] == a * 10 + b + c;
        loop invariant max_sum[1] == a + b * 10 + c;
        loop invariant max_sum[2] == a + b + c * 10;
        loop invariant max_value == max_sum[0] ||
                         max_value == max_sum[1] ||
                         max_value == max_sum[2];
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= max_sum[k];
        loop assigns i, max_value;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (max_sum[i] > max_value)
        {
            max_value = max_sum[i];
        }
        //@ assert max_value >= max_sum[i];
        i++;
    }
    //@ assert max_value == max_sum[0] || max_value == max_sum[1] || max_value == max_sum[2];
    return max_value;
}
