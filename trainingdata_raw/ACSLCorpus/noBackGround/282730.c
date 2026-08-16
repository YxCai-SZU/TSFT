/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    requires ((a) < (b));
    requires ((c) < (d));
    ensures \result == 1 <==> (!((b) < (c) || (a) > (d)));
*/
int func(int a, int b, int c, int d)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((a) < (b));
    //@ assert ((c) < (d));
    return !(b < c || a > d);
}
