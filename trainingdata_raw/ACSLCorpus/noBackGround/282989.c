/*@
    requires (1 <= (a) && (a) <= (b) && (b) <= 20);
    ensures \result == (((b) - (a) + 1) * 2 - 1);
    assigns \nothing;
*/
long func(unsigned long a, unsigned long b)
{
    unsigned long c;
    unsigned long d;
    long e;
    long f;

    c = b - a;
    d = c + 1;
    //@ assert d <= 21;
    //@ assert d * 2 <= 42;
    e = (long)d * 2;
    f = e - 1;
    //@ assert f == (((b) - (a) + 1) * 2 - 1);
    return f;
}
