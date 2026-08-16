/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a + b) / 2 + (a + b) % 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int quotient = 0;
    int remainder;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    sum = a + b;
    remainder = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant sum == a + b;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == sum - 2 * quotient;
        loop invariant quotient <= sum / 2;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        quotient += 1;
        remainder -= 2;
    }

    //@ assert remainder == sum - 2 * quotient;
    result = quotient + remainder;
    //@ assert result == ((sum) / 2 + (sum) % 2);
    return result;
}
