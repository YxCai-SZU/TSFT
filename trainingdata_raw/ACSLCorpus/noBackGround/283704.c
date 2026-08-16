/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
_Bool func(long n, long m) {
    // Variable declarations at top of scope
    long ans;
    _Bool result;
    
    //@ assert 0 <= n <= 100;
    //@ assert 0 <= m <= n;
    //@ assert n >= m;
    //@ assert n - m >= 0;
    //@ assert n - m <= n;
    
    ans = n - m;
    result = (ans == 0);
    
    return result;
}

int main() {
    return 0;
}
