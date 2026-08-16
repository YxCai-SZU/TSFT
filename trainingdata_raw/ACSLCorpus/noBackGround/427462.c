/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    requires (1 <= (d) && (d) <= 100);
    requires ((a) < (b));
    requires ((c) < (d));
    ensures \result == 1 <==> (!((b) < (c) || (d) < (a)));
*/
_Bool func(long long a, long long b, long long c, long long d)
{
    //@ assert ((a) < (b));
    //@ assert ((c) < (d));
    return !(b < c || d < a);
}
