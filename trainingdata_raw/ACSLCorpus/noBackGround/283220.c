/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
long func(long r)
{
    long pi = 314;
    long result = 0;
    long temp = 2 * r * pi;
    long count = 0;

    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (pi) == 314 &&
        (temp) >= 0 &&
        (temp) == 2 * (r) * (pi) - 100 * (count) &&
        (count) >= 0);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        count += 1;
    }
    result = count;

    //@ assert result == ((2 * (r) * 314) / 100);
    return result;
}
