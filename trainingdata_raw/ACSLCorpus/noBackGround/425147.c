#include <stdint.h>

/*@
    requires n < 1000;
    ensures \result == n * (n + 1) / 2;
    ensures ((\result) == (n) * ((n) + 1) / 2);
*/
uint32_t is_triangular(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t ret;

    //@ assert 0 <= n < 1000;
    //@ assert 0 <= n * (n + 1) / 2 < 500500;
    
    ret = n * (n + 1) / 2;
    
    //@ assert ret == n * (n + 1) / 2;
    //@ assert ((ret) == (n) * ((n) + 1) / 2);
    
    return ret;
}

int main() {
    return 0;
}
