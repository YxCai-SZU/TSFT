#include <stdint.h>

/*@ predicate bounds(integer a, integer b) =
      1 <= a && a < 100 &&
      1 <= b && b < 100;
*/

/*@ logic integer product(integer a, integer b) = a * b; */

/*@ lemma product_bounds: 
      \forall integer a, b; 
      bounds(a, b) ==> product(a, b) < 10000;
*/

/*@ requires bounds(a, b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert a < 100;
    //@ assert b < 100;
    //@ assert a * b < 10000;
    
    //@ assert a * b == a * b;
    
    result = a * b;
    return result;
}
