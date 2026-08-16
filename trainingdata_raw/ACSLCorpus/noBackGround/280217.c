/*@
    requires 1 <= n <= 9;
    ensures \result == n * n * n;
    assigns \nothing;
*/
unsigned long func(unsigned long n) {
    unsigned long result;
    
    //@ assert 1 <= n && n <= 9;
    //@ assert n * n <= 81;
    //@ assert n * n * n <= 729;
    
    result = n * n * n;
    return result;
}

int main() {
    return 0;
}
