#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000000000 &&
        1 <= (k) && (k) <= 1000000000);
    ensures \result <= k;
    ensures \result >= 0;
    ensures \result <= n % k;
    ensures \result == n % k || \result == k - n % k;
*/
uint64_t func(uint64_t n, uint64_t k) {
    uint64_t remainder;
    uint64_t complement;
    uint64_t min_val;

    //@ assert (1 <= (n) && (n) <= 1000000000000000000 &&         1 <= (k) && (k) <= 1000000000);
    
    remainder = n % k;
    
    if (remainder == 0) {
        //@ assert remainder == 0;
        //@ assert 0 <= k;
        //@ assert 0 == n % k;
        return 0;
    } else {
        complement = k - remainder;
        
        //@ assert remainder > 0;
        //@ assert complement > 0;
        
        if (remainder < complement) {
            min_val = remainder;
        } else {
            min_val = complement;
        }
        
        //@ assert min_val == remainder || min_val == complement;
        //@ assert min_val <= k;
        //@ assert min_val >= 0;
        //@ assert min_val <= remainder;
        
        return min_val;
    }
}
