/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 314159 * r) / 100000;
*/
long func(long r)
{
    long pi;
    long scale;
    long circumference;
    long temp;

    pi = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi * r;

    /*@
        loop invariant (1 <= (r) && (r) <= 100);
        loop invariant ((pi) == 314159);
        loop invariant ((scale) == 100000);
        loop invariant ((temp) >= 0);
        loop invariant ((circumference) * (scale) + (temp) == 2 * (pi) * (r));
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        circumference = circumference + 1;
        temp = temp - scale;
    }

    return circumference;
}
