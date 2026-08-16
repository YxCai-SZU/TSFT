/*@
    requires (0 <= (A) && (A) <= 1000000000000000000 &&
        0 <= (B) && (B) <= 1000000000000000000 &&
        0 <= (C) && (C) <= 1000000000000000000 &&
        1 <= (K) && (K) <= 1000000000000000000 &&
        (A) + (B) + (C) >= (K));
    ensures -C <= \result && \result <= A;
    assigns \nothing;
*/
long long func(long long A, long long B, long long C, long long K)
{
    long long res;
    long long rst;
    
    res = 0;
    rst = K;
    
    //@ assert -C <= res && res <= A;
    //@ assert 0 <= (((A) < (rst)) ? (A) : (rst)) && (((A) < (rst)) ? (A) : (rst)) <= 1000000000000000000;
    //@ assert res + (((A) < (rst)) ? (A) : (rst)) >= -C && res + (((A) < (rst)) ? (A) : (rst)) <= A;
    res += (A < rst) ? A : rst;
    rst -= (A < rst) ? A : rst;
    
    //@ assert 0 <= rst && rst <= 1000000000000000000;
    //@ assert 0 <= (((B) < (rst)) ? (B) : (rst)) && (((B) < (rst)) ? (B) : (rst)) <= 1000000000000000000;
    //@ assert rst - (((B) < (rst)) ? (B) : (rst)) >= 0 && rst - (((B) < (rst)) ? (B) : (rst)) <= 1000000000000000000;
    rst -= (B < rst) ? B : rst;
    
    //@ assert -C <= res && res <= A;
    //@ assert 0 <= (((C) < (rst)) ? (C) : (rst)) && (((C) < (rst)) ? (C) : (rst)) <= 1000000000000000000;
    //@ assert res - (((C) < (rst)) ? (C) : (rst)) >= -C && res - (((C) < (rst)) ? (C) : (rst)) <= A;
    res -= (C < rst) ? C : rst;
    
    return res;
}
