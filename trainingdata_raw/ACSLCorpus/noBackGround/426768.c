/*@
    requires ((((A)) >= 0) && (((B)) >= 0) && (((C)) >= 0) &&
        1 <= (K) && (K) <= (A) + (B) + (C) && (A) + (B) + (C) <= 2000000000);
    ensures ((\result) <= (K));
    assigns \nothing;
*/
int func(int A, int B, int C, int K)
{
    int ans = 0;
    int rst = K;

    //@ assert ((A) >= 0) && ((B) >= 0) && ((C) >= 0);
    //@ assert 1 <= K && K <= A + B + C && A + B + C <= 2000000000;

    if (A >= rst) {
        ans += rst;
        rst -= rst;
    } else {
        ans += A;
        rst -= A;
    }

    if (B >= rst) {
        rst -= rst;
    } else {
        rst -= B;
    }

    //@ assert ans <= K;

    ans -= rst;
    return ans;
}
