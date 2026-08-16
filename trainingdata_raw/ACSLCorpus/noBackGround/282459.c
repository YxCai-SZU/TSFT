#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
size_t func(size_t n) {
    // Variable declarations at top
    size_t res;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 100 * 100;
    //@ assert n * n >= 1 * 1;
    
    res = n * n;
    
    //@ assert res == ((n) * (n));
    return res;
}

int main() {
    return 0;
}
