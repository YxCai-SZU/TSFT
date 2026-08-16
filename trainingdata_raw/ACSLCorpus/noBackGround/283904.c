/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
    assigns \nothing;
*/
int func(int A, int P)
{
    int sum;
    int result;
    int temp_sum;
    int count;

    //@ assert (0 <= (A) <= 100 && 0 <= (P) <= 100);
    sum = A * 3 + P;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum == sum - 2 * count;
    }

    result = count;
    //@ assert result >= 0;
    //@ assert result <= ((A) * 3 + (P));
    return result;
}

int main()
{
    return 0;
}
