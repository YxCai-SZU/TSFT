#include <stdint.h>

/*@
    predicate is_triangular(integer n, integer ret) =
        ret == n * (n + 1) / 2;
    
    lemma triangular_bound:
        \forall integer n; 0 <= n <= 65535 ==> n * (n + 1) / 2 <= 2147483647;
*/

/*@
    requires n <= 65535;
    ensures \result == n * (n + 1) / 2;
    ensures \result <= 2147483647;
*/
uint32_t is_triangular(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n <= 65535;
    
    //@ assert n * (n + 1) / 2 <= 2147483647;
    
    //@ assert n * (n + 1) / 2 >= 0;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == n * (n + 1) / 2;
    
    //@ assert result <= 2147483647;
    
    return result;
}

int main() {
    return 0;
}
