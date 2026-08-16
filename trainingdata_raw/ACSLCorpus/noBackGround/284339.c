/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
*/
long func(long a, long b, long c, long d) {
    long sa;
    long sc;
    long result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert 1 <= ((a) * (b)) <= 10000 * 10000;
    sa = a * b;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert 1 <= ((c) * (d)) <= 10000 * 10000;
    sc = c * d;

    if (sa > sc) {
        result = sa;
    } else {
        result = sc;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= 1;

    return result;
}
