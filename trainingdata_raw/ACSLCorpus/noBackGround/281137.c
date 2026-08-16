/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (a + b) / 2 || \result == (a + b) / 2 + 1;
*/
int func(int a, int b)
{
    int sum;
    int avg;
    int remainder;

    sum = a + b;
    avg = 0;
    remainder = sum;

    /*@
        loop invariant 0 <= avg;
        loop invariant avg <= sum / 2;
        loop invariant sum == a + b;
        loop invariant remainder == sum - 2 * avg;
        loop invariant (1 <= (a) <= 100);
        loop invariant (1 <= (b) <= 100);
        loop assigns avg, remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        avg += 1;
        remainder -= 2;
    }

    if (remainder > 0)
    {
        //@ assert remainder == 1;
        avg += 1;
    }

    //@ assert avg == (a + b) / 2 || avg == (a + b) / 2 + 1;
    return avg;
}
