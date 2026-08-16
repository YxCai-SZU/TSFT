#include <stdint.h>

/*@ requires (0 <= (n) && (n) <= 65535);
    ensures \result == (((n) * ((n) + 1)) / 2);
    ensures \result <= n * n;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n + 1 <= 65536;
    
    //@ assert n * (n + 1) <= 4294967295;
    
    //@ assert (n * (n + 1)) / 2 <= 2147483647;
    
    //@ assert (n * (n + 1)) / 2 <= n * n;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == (((n) * ((n) + 1)) / 2);
    //@ assert result <= n * n;
    
    return result;
}
