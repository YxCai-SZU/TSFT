#include <stdint.h>

/*@
    requires 1 <= n && n <= 10000;
    ensures \result == 0;
    assigns \nothing;
*/
int func(uint32_t n) {
    // Variable declarations at scope top
    int result = 0;
    
    //@ assert 1 <= n && n <= 10000;
    
    //@ assert n * n * n <= 10000 * 10000 * 10000;
    
    return result;
}

int main() {
    return 0;
}
