/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100);
    ensures \result == n + m && \result <= 200;
    assigns \nothing;
*/
int add_with_bound(int n, int m) {
    //@ assert (0 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= 100);
    int result = n + m;
    //@ assert result <= 200;
    return result;
}

/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100);
    ensures \result == n + m && \result <= 200;
    assigns \nothing;
*/
int add_with_bound_2(int n, int m) {
    //@ assert (0 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= 100);
    int result = n + m;
    //@ assert result <= 200;
    return result;
}
