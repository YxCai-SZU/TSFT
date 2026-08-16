/*@
    predicate valid_inputs(integer A, integer B, integer C, integer K) =
        0 <= A && 0 <= B && 0 <= C &&
        1 <= K && K <= A + B + C &&
        A + B + C <= 200000000000000000;

    logic integer compute_res(integer A, integer B, integer C, integer K) =
        K <= A ? K : (K <= A + B ? A : A - (K - A - B));

    lemma res_bounds: \forall integer A, B, C, K;
        valid_inputs(A, B, C, K) ==> 
            compute_res(A, B, C, K) <= A && compute_res(A, B, C, K) >= -C;
*/

/*@
    requires valid_inputs(A, B, C, K);
    ensures \result <= A;
    ensures \result >= -C;
    ensures \result == compute_res(A, B, C, K);
*/
long func(long A, long B, long C, long K)
{
    long res = 0;
    long remaining_k = K;

    //@ assert valid_inputs(A, B, C, K);
    
    if (A >= remaining_k) {
        res += remaining_k;
        remaining_k = 0;
    } else {
        res += A;
        remaining_k -= A;
    }

    if (remaining_k == 0) {
        //@ assert res == compute_res(A, B, C, K);
        return res;
    }

    if (B >= remaining_k) {
        remaining_k = 0;
    } else {
        remaining_k -= B;
    }

    if (remaining_k == 0) {
        //@ assert res == compute_res(A, B, C, K);
        return res;
    }

    res -= remaining_k;
    remaining_k = 0;

    //@ assert res == compute_res(A, B, C, K);
    return res;
}
