/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int a_min_k;
    int b_min_k;
    int c_min_k;
    int result;

    k_remaining = k;

    //@ assert k_remaining == k;
    //@ assert 0 <= k_remaining && k_remaining <= 1000000000;

    if (a < k_remaining) {
        a_min_k = a;
    } else {
        a_min_k = k_remaining;
    }
    //@ assert a_min_k == (((a) < (k)) ? (a) : (k));
    k_remaining = k_remaining - a_min_k;
    //@ assert k_remaining == k - (((a) < (k)) ? (a) : (k));

    if (b < k_remaining) {
        b_min_k = b;
    } else {
        b_min_k = k_remaining;
    }
    //@ assert b_min_k == (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))));
    k_remaining = k_remaining - b_min_k;
    //@ assert k_remaining == k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))));

    if (c < k_remaining) {
        c_min_k = c;
    } else {
        c_min_k = k_remaining;
    }
    //@ assert c_min_k == (((c) < (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k)))))) ? (c) : (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))))));
    k_remaining = k_remaining - c_min_k;
    //@ assert k_remaining == k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k)))) - (((c) < (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k)))))) ? (c) : (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))))));

    result = a_min_k - c_min_k;
    //@ assert result == (((a) < (k)) ? (a) : (k)) - (((c) < (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k)))))) ? (c) : (k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))))));

    //@ assert result >= -c && result <= a;
    return result;
}
