/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate k_in_range(integer k, integer a, integer b, integer c) =
        1 <= k && k <= a + b + c;

    logic integer compute_a(integer A, integer K) =
        (A < K) ? A : K;

    logic integer compute_b(integer B, integer K, integer a) =
        (B < K - a) ? B : K - a;

    logic integer compute_c(integer C, integer K, integer a, integer b) =
        (C < K - a - b) ? C : K - a - b;

    logic integer compute_ans(integer a, integer b, integer c, integer K) =
        a - (K - a - b - c);

    lemma ans_bound_lemma:
        \forall integer A, B, C, K;
        non_negative(A, B, C) && k_in_range(K, A, B, C) ==>
        compute_ans(compute_a(A, K), compute_b(B, K, compute_a(A, K)), 
                   compute_c(C, K, compute_a(A, K), compute_b(B, K, compute_a(A, K))), K) 
        <= A + B + C;
*/

/*@
    requires non_negative(A, B, C) && k_in_range(K, A, B, C);
    ensures \result <= A + B + C && \result >= K - (B + C);
    assigns \nothing;
*/
int func(int A, int B, int C, int K)
{
    int k = K;
    int ans = 0;
    int a, b, c;

    // First conditional block
    if (A < k) {
        a = A;
    } else {
        a = k;
    }
    ans += a;
    k -= a;

    // Second conditional block
    if (B < k) {
        b = B;
    } else {
        b = k;
    }
    k -= b;

    // Third conditional block
    if (C < k) {
        c = C;
    } else {
        c = k;
    }
    k -= c;

    ans -= k;

    //@ assert ans <= A + B + C;
    //@ assert ans >= K - (B + C);

    return ans;
}
