/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100 &&
        1 <= k && k <= 100 &&
        a + b + c >= k;

    predicate valid_output(integer res, integer k, integer a) =
        res >= -k && res <= k && res <= a;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures valid_output(\result, k, a);
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int k_remaining;
    int b_cnt;
    int c_cnt;
    int res;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    //@ assert 1 <= k && k <= 100;
    //@ assert a + b + c >= k;

    if (k < a) {
        a_cnt = k;
    } else {
        a_cnt = a;
    }
    //@ assert 0 <= a_cnt && a_cnt <= a && a_cnt <= k;

    k_remaining = k - a_cnt;
    //@ assert 0 <= k_remaining && k_remaining <= k;

    if (k_remaining < b) {
        b_cnt = k_remaining;
    } else {
        b_cnt = b;
    }
    //@ assert 0 <= b_cnt && b_cnt <= b && b_cnt <= k_remaining;

    k_remaining -= b_cnt;
    //@ assert 0 <= k_remaining && k_remaining <= k - a_cnt - b_cnt;

    if (k_remaining < c) {
        c_cnt = k_remaining;
    } else {
        c_cnt = c;
    }
    //@ assert 0 <= c_cnt && c_cnt <= c && c_cnt <= k_remaining;

    res = a_cnt - c_cnt;
    //@ assert res >= -k && res <= k;
    //@ assert res <= a;

    return res;
}
