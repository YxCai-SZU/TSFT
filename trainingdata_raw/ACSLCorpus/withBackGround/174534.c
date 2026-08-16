#include <stdint.h>

/*@
    predicate v1_bounds(integer v1) = 0 <= v1 <= 1000000000;
    predicate v2_bounds(integer v2) = 0 <= v2 < 1000;
    predicate product_bounds(integer v1, integer v2) = v1 * v2 <= 1000000000 * 999;
    
    lemma product_bound_lemma: 
        \forall integer v1, v2; v1_bounds(v1) && v2_bounds(v2) ==> product_bounds(v1, v2);
*/

/*@
    requires 0 <= v1 <= 1000000000;
    requires 0 <= v2 < 1000;
    ensures \result == (v1 * v2) / 100;
    assigns \nothing;
*/
uint64_t func(uint64_t v1, uint64_t v2) {
    // Variable declarations at top of scope
    uint64_t res;
    
    //@ assert v1 <= 1000000000;
    //@ assert v2 < 1000;
    //@ assert v1 * v2 <= 1000000000 * 999;
    
    res = (v1 * v2) / 100;
    return res;
}

int main() {
    return 0;
}
