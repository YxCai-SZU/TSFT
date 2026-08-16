/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int sa;
    int sc;
    int result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;

    sa = a * b;
    sc = c * d;

    if (sa > sc) {
        result = sa;
    } else {
        result = sc;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= ((a) * (b)) && result >= ((c) * (d));

    return result;
}
