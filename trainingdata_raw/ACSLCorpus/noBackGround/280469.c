/*@
    requires (1 <= (a) <= 100);
    ensures ((\result) == 2 * 314159 * (a) / 100000);
    assigns \nothing;
*/
long func(long a)
{
    long pi;
    long scale;
    long result;
    long temp;
    long count;

    pi = 314159;
    scale = 100000;
    result = 0;
    temp = a * 2 * pi;
    count = 0;

    /*@
        loop invariant (1 <= (a) <= 100);
        loop invariant ((pi) == 314159);
        loop invariant ((scale) == 100000);
        loop invariant ((temp) >= 0);
        loop invariant ((count) >= 0);
        loop invariant ((temp) == (a) * 2 * (pi) - (count) * (scale));
        loop assigns temp, count;
        loop variant ((temp));
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp = temp - scale;
        count = count + 1;
        //@ assert ((temp) == (a) * 2 * (pi) - (count) * (scale));
    }

    //@ assert temp >= 0;
    //@ assert temp < scale;
    //@ assert ((count) * (scale) + (temp) == (a) * 2 * (pi));
    result = count;

    //@ assert ((result) == 2 * 314159 * (a) / 100000);
    return result;
}
