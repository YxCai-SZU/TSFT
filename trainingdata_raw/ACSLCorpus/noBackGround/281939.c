/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (100 * ((n) - (m)) + 1900 * (m)) * 2;
*/
int func(int n, int m) {
    int ans;
    int shift_count;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= (n) &&         (m) <= 5);
    ans = 100 * (n - m) + 1900 * m;
    shift_count = m;

    /*@
        loop invariant 0 <= shift_count <= m;
        loop invariant ans == ((100 * (((n)) - ((m))) + 1900 * ((m))) + 100 * ((m) - (shift_count)));
        loop invariant ans >= (100 * ((n) - (m)) + 1900 * (m));
        loop invariant ans <= (100 * ((n) - (m)) + 1900 * (m)) * 2;
        loop assigns ans, shift_count;
    */
    while (shift_count > 0) {
        //@ assert shift_count > 0;
        ans += 100;
        shift_count -= 1;
    }

    //@ assert ans == ((100 * (((n)) - ((m))) + 1900 * ((m))) + 100 * ((m) - (0)));
    return ans;
}
