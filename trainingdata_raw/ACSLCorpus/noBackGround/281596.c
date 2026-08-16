/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
long func(long a, long b) {
    long res;
    //@ assert 1 <= a - 1 <= 99;
    //@ assert 1 <= b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) <= 99 * 99;
    res = (a - 1) * (b - 1);
    return res;
}
