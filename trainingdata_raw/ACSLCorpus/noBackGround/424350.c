/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (3) * (r));
    assigns \nothing;
*/
long func(long r)
{
    long pi = 3;
    long circumference = 2 * pi * r;
    long i = 0;

    /*@
        loop invariant 0 <= i <= r;
        loop invariant circumference == (2 * (pi) * (r));
        loop invariant (1 <= (r) && (r) <= 100);
        loop invariant (2 * (pi) * (r)) >= 2 * 3 * 1;
        loop invariant (2 * (pi) * (r)) <= 2 * 3 * 100;
        loop assigns i;
        loop variant r - i;
    */
    while (i < r)
    {
        i = i + 1;
    }

    return circumference;
}

int main()
{
    return 0;
}
