/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * (a));
    assigns \nothing;
*/
long func(long a)
{
    long res;
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert ((a) * (a)) <= 10000;
    res = a * a;
    return res;
}
