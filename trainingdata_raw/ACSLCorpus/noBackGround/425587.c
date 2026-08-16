/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long scaled_r;
    long circumference;
    long temp;
    long divisor;

    pi_approx = 314;
    scaled_r = r * 100;
    circumference = 0;
    temp = 2 * scaled_r * pi_approx;
    divisor = 10000;

    //@ assert (1 <= (r) <= 100);
    //@ assert (314)== 314;
    //@ assert scaled_r == r * 100;
    //@ assert divisor == 10000;
    //@ assert 0 <= circumference;
    //@ assert temp >= 0;
    //@ assert circumference * 10000 + temp == 2 * scaled_r * (314);

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314)== 314;
        loop invariant scaled_r == r * 100;
        loop invariant divisor == 10000;
        loop invariant 0 <= circumference;
        loop invariant temp >= 0;
        loop invariant circumference * 10000 + temp == 2 * scaled_r * (314);
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }

    //@ assert circumference == 2 * r * 314 / 100;
    return circumference;
}
