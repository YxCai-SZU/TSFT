/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
*/
int func(int n, int a) {
    // Variable declarations at scope top
    int result;
    
    //@ assert 0 <= a;
    //@ assert a <= n * n;
    //@ assert 1 <= n;
    //@ assert n <= 100;
    //@ assert 0 <= n * n;
    //@ assert n * n - a >= 0;
    
    result = n * n - a;
    return result;
}

int main() {
    return 0;
}
