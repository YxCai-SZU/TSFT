#include <stdint.h>

/*@
    predicate bounds(uint32_t a, uint32_t b) =
        a > 0 && a < 0x10000 &&
        b > 0 && b < 0x10000;
        
    lemma no_overflow:
        \forall uint32_t a, b;
            bounds(a, b) ==> (uint64_t)a * b < 0x100000000;
*/

/*@
    requires bounds(a, b);
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    //@ assert bounds(a, b);
    
    //@ assert (uint64_t)a * b < 0x100000000;
    
    uint32_t res = a * b;
    
    //@ assert res == a * b;
    
    return res;
}
