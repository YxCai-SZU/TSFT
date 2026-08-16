/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == (A + B) / 2;
    assigns \nothing;
*/
int func(int A, int B)
{
    int sum;
    int avg;
    int count;

    sum = A + B;
    avg = 0;
    count = sum;

    /*@
        loop invariant 0 <= avg;
        loop invariant avg <= sum / 2;
        loop invariant sum == A + B;
        loop invariant 0 <= count <= sum;
        loop invariant count + 2 * avg == sum;
        loop assigns avg, count;
        loop variant count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        avg += 1;
        count -= 2;
        //@ assert count + 2 * avg == sum;
    }

    //@ assert avg == (A + B) / 2;
    return avg;
}
