#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= (n));
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % k == 0;
    ensures \result == 1 ==> n % k != 0;
*/
int32_t func(uint32_t n, uint32_t k) {
    // Variable declarations at scope top
    int32_t result;
    uint32_t remainder;

    remainder = n % k;
    
    if (remainder == 0) {
        result = 0;
        //@ assert result == 0;
        return result;
    } else {
        //@ assert remainder != 0;
        //@ assert remainder < k;
        //@ assert n <= 100;
        //@ assert k <= n;
        result = 1;
        //@ assert result == 1;
        return result;
    }
}
