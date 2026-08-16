/*@
    predicate nonnegative(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c && 1 <= k &&
        k <= a + b + c && a + b + c <= 2000000000;

    logic integer min_a_k(integer a, integer k) = (a < k) ? a : k;
    logic integer min_k_a_b(integer k, integer a, integer b, integer c) =
        (k - a - b < c) ? k - a - b : c;
    logic integer max_min_k_a_b_0(integer k, integer a, integer b, integer c) =
        (min_k_a_b(k, a, b, c) < 0) ? 0 : min_k_a_b(k, a, b, c);

    lemma max_min_nonnegative:
        \forall integer k, a, b, c;
        nonnegative(a, b, c, k) ==> max_min_k_a_b_0(k, a, b, c) >= 0;

    lemma result_bounds:
        \forall integer k, a, b, c, res;
        nonnegative(a, b, c, k) && res == k - max_min_k_a_b_0(k, a, b, c) ==>
        res <= a + b + c && res >= k - b - c;
*/

/*@
    requires nonnegative(a, b, c, k);
    ensures \result <= a + b + c;
    ensures \result >= k - b - c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int min_a_k;
    int min_k_a_b;
    int max_min_k_a_b_0;
    int res;

    //@ assert nonnegative(a, b, c, k);

    min_a_k = (a < k) ? a : k;
    //@ assert min_a_k == min_a_k(a, k);

    min_k_a_b = (k - a - b < c) ? k - a - b : c;
    //@ assert min_k_a_b == min_k_a_b(k, a, b, c);

    max_min_k_a_b_0 = (min_k_a_b < 0) ? 0 : min_k_a_b;
    //@ assert max_min_k_a_b_0 == max_min_k_a_b_0(k, a, b, c);

    //@ assert max_min_k_a_b_0 >= 0;

    res = k - max_min_k_a_b_0;
    //@ assert res == k - max_min_k_a_b_0(k, a, b, c);

    //@ assert res <= a + b + c;
    //@ assert res >= k - b - c;

    return res;
}
