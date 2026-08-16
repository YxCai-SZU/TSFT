/*@
    requires (1 <= (N) <= 100) && (1 <= (M) <= 100);
    ensures ((\result) >= 0 && (\result) <= (N) + (M));
*/
long func(long N, long M) {
    long max_val;
    long min_val;
    long diff;
    long result;

    if (N > M) {
        max_val = N;
    } else {
        max_val = M;
    }

    if (N < M) {
        min_val = N;
    } else {
        min_val = M;
    }

    diff = max_val - min_val;

    if (diff < 2 * min_val + 1) {
        //@ assert diff >= 0;
        //@ assert diff <= N + M;
        result = diff;
    } else {
        //@ assert 2 * min_val + 1 >= 0;
        //@ assert 2 * min_val + 1 <= N + M;
        result = 2 * min_val + 1;
    }

    return result;
}
