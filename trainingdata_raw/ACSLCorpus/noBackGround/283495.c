/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int remainder = n;
    int three = 3;

    /*@
        loop invariant (1 <= (n) <= 1000 &&
        0 <= (result) &&
        0 <= (remainder) <= (n) &&
        (n) == (remainder) + (result) * (three));
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= three)
    {
        remainder -= three;
        result += 1;
    }

    return result;
}
