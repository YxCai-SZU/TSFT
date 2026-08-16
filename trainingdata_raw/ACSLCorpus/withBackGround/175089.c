#include <stdint.h>

/*@ predicate triangular_formula(integer n, integer result) =
    n >= 0 && n <= 65535 && result == n * (n + 1) / 2;
*/

/*@ lemma no_overflow: 
    \forall integer n; 0 <= n <= 65535 ==> n * (n + 1) <= 4294967295;
*/

/*@ lemma division_safe: 
    \forall integer n; 0 <= n <= 65535 ==> n * (n + 1) / 2 <= 2147483647;
*/

/*@ requires n <= 65535;
    ensures \result == n * (n + 1) / 2;
    ensures \result == (unsigned long long)n * ((unsigned long long)n + 1) / 2;
*/
uint32_t find_triangular_num(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n * (n + 1) <= 4294967295;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == n * (n + 1) / 2;
    return result;
}
