#include <stdint.h>

/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x && 1 <= y && 1 <= z &&
        x <= 100000 && y <= 100000 && z <= 100000 &&
        y + 2 * z <= x;

    logic integer compute_n(integer x, integer y, integer z) =
        (x - z) / (y + z);

    lemma n_bound: \forall integer x, y, z;
        valid_params(x, y, z) ==> compute_n(x, y, z) * (y + z) <= x;
*/

/*@
    requires valid_params(x, y, z);
    ensures \result <= x;
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z) {
    // Variable declarations at scope top
    uint64_t n;
    uint64_t result;
    
    //@ assert valid_params(x, y, z);
    
    n = (x - z) / (y + z);
    
    //@ assert n * (y + z) <= x;
    
    result = n * (y + z) + (x - n * (y + z));
    
    if (result < x) {
        result += 1;
    }
    
    //@ assert result <= x;
    
    return result;
}
