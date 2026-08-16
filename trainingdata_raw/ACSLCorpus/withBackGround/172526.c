#include <stdint.h>

/*@
    predicate division_nonlinear(integer x, integer y) =
        y > 0 && x >= y ==> x / y <= x;
*/

/*@
    lemma verify_division_is_nonlinear:
        \forall integer x, y; division_nonlinear(x, y);
*/

int main() {
    uint32_t x;
    uint32_t y;
    
    //@ ghost int proof_x;
    //@ ghost int proof_y;
    
    //@ assert division_nonlinear(proof_x, proof_y);
    
    return 0;
}
