/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == (A + B + C) / 3;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int sum;
    int result;
    int temp_sum;
    int count;

    //@ assert (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    sum = A + B + C;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 1 <= A <= 100;
        loop invariant 1 <= B <= 100;
        loop invariant 1 <= C <= 100;
        loop invariant temp_sum >= 0;
        loop invariant sum == A + B + C;
        loop invariant temp_sum + 3 * count == sum;
        loop invariant count >= 0;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 3)
    {
        //@ assert temp_sum >= 3;
        temp_sum -= 3;
        //@ assert temp_sum >= 0;
        count += 1;
        //@ assert count >= 0;
    }

    result = count;
    //@ assert result == (A + B + C) / 3;
    return result;
}
