/*@
    requires ((((A)) >= 0) && (((B)) >= 0) && (((C)) >= 0) &&
        1 <= (K) && (K) <= (A) + (B) + (C) && (A) + (B) + (C) <= 2000000000);
    ensures \result <= K;
    ensures \result >= 0;
    assigns \nothing;
*/
long func(long A, long B, long C, long K)
{
    long ans;
    long rst;
    long tmp1;
    long tmp2;
    long tmp3;
    long tmp4;
    long tmp5;

    ans = 0;
    rst = K;

    //@ assert ans >= 0 && rst >= 0;

    tmp1 = A < rst ? A : rst;
    ans = ans + tmp1;
    tmp2 = A < rst ? A : rst;
    rst = rst - tmp2;

    //@ assert ans >= 0 && rst >= 0;

    tmp3 = B < rst ? B : rst;
    rst = rst - tmp3;

    //@ assert ans >= 0;

    tmp4 = rst < 0 ? -rst : 0;
    ans = ans - tmp4;

    //@ assert ans >= -K && ans <= K;

    tmp5 = ans > 0 ? ans : 0;
    ans = tmp5;

    //@ assert ans >= 0 && ans <= K;

    return ans;
}
