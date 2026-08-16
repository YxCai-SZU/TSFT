/*@
    predicate valid_input(integer A, integer B, integer C, integer K) =
        0 <= A && A <= 1000000000 &&
        0 <= B && B <= 1000000000 &&
        0 <= C && C <= 1000000000 &&
        1 <= K && K <= 1000000000 &&
        A + B + C >= K;

    logic integer compute_ans(integer A, integer B, integer C, integer K) =
        (A >= K) ? K : A - ((B >= (K - A)) ? 0 : (K - A - B));

    lemma ans_bounds: \forall integer A, B, C, K;
        valid_input(A, B, C, K) ==> 
            compute_ans(A, B, C, K) >= -C && compute_ans(A, B, C, K) <= A;
*/

/*@
    requires valid_input(A, B, C, K);
    ensures \result >= -C && \result <= A;
    assigns \nothing;
*/
long func(long A, long B, long C, long K)
{
    long ans = 0;
    long k = K;

    //@ ghost long old_k = k;
    //@ ghost long old_ans = ans;

    if (A >= k)
    {
        ans += k;
    }
    else
    {
        ans += A;
    }
    k -= A;

    //@ assert ans == ((A >= old_k) ? old_k : A);
    //@ assert k == old_k - A;

    //@ ghost old_k = k;
    //@ ghost old_ans = ans;

    if (B >= k)
    {
        k -= k;
    }
    else
    {
        k -= B;
    }

    //@ assert k == ((B >= old_k) ? 0 : old_k - B);

    //@ ghost old_ans = ans;
    ans -= k;

    //@ assert ans == old_ans - k;

    return ans;
}
