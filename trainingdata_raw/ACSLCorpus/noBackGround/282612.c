/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * r * 314) / 100;
    assigns \nothing;
*/
long func(long r)
{
    long pi;
    long two;
    long hundred;
    long result;
    long temp;
    long count;

    pi = 314;
    two = 2;
    hundred = 100;
    result = 0;
    temp = two * r * pi;
    count = 0;

    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi) == 314 &&
        (two) == 2 &&
        (hundred) == 100 &&
        (temp) >= 0 &&
        (temp) == (two) * (r) * (pi) - (hundred) * (count) &&
        (count) >= 0 &&
        (count) * (hundred) + (temp) == (two) * (r) * (pi) &&
        (count) * (hundred) <= (two) * (r) * (pi));
        loop assigns temp, count;
        loop variant ((temp));
    */
    while (temp >= hundred)
    {
        //@ assert temp >= 100;
        temp = temp - hundred;
        count = count + 1;
    }
    result = count;

    //@ assert two * r * pi <= 2 * 100 * 314;
    //@ assert two * r * pi >= 2 * 1 * 314;

    return result;
}
