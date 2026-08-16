/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (a + b >= c);
*/
int func(long long a, long long b, long long c)
{
    long long ab;
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    ab = a + b;
    //@ assert ab == ((a) + (b));
    //@ assert 1 <= ab <= 200;
    result = (ab >= c);
    return result;
}
