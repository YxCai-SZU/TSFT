/*@
    requires (1 <= (r) && (r) <= 100);
    ensures ((\result) == 6 * (r));
    assigns \nothing;
*/
long func(long r)
{
    long pi;
    long circumference;

    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (6 * (r)) <= 600;

    pi = 3;
    circumference = 2 * r * pi;

    //@ assert ((circumference) == 6 * (r));
    return circumference;
}
