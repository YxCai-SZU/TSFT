#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a) {
    // Variable declarations at top of scope
    int64_t result;
    
    // Precondition verification
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    
    //@ assert n * n <= 10000;
    //@ assert 0 <= n * n - a && n * n - a <= 10000;
    
    result = n * n - a;
    
    // Postcondition verification
    //@ assert result == ((n) * (n) - (a));
    
    return result;
}

int main() {
    return 0;
}
