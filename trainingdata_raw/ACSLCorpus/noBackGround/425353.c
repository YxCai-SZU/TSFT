/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
    assigns \nothing;
*/
long func(long n, long m) {
    long n_minus_2m;
    long result;

    //@ assert n >= 0;
    //@ assert m >= 0;
    //@ assert 2 * m <= 200;

    n_minus_2m = n - 2 * m;

    if (n_minus_2m > 0) {
        result = n_minus_2m;
    } else {
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
