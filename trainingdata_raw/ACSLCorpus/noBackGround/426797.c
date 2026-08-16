/*@
    requires (1 <= (a) && (a) <= 100);
    requires (0 <= (b) && (b) <= (a) * (a));
    ensures \result == a * a - b;
*/
int func(int a, int b)
{
    // Variable declarations at top
    int res;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= (a) * (a));
    //@ assert a * a >= 0;
    //@ assert ((a) * (a) <= 10000);

    res = a * a - b;
    return res;
}
