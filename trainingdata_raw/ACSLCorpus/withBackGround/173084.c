/*@
    predicate valid_input(integer r, integer g) =
        0 <= r <= 4500 &&
        0 <= g <= 4500 &&
        r != g;

    logic integer compute_b(integer r, integer g) =
        2 * g - r;
*/

/*@
    requires valid_input(r, g);
    ensures \result == compute_b(r, g);
    assigns \nothing;
*/
int func(int r, int g) {
    // Variable declarations at top of scope
    int b;

    //@ assert 0 <= r <= 4500;
    //@ assert 0 <= g <= 4500;
    //@ assert r != g;

    b = 2 * g - r;
    return b;
}
