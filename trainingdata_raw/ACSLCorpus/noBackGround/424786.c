/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000 &&
        500 * (k) <= 100000);
    ensures \result == (500 * k >= x);
*/
int func(int k, int x) {
    // Variable declarations at scope top
    int result;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    //@ assert 500 * k <= 100000;

    result = (500 * k >= x);
    return result;
}
