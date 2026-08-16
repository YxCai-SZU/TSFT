#include <stdbool.h>

/*@ predicate is_valid_u32(unsigned int x) = x <= 0xffffffff; */

/*@ lemma or_commutative: 
      \forall unsigned int a, b; 
      is_valid_u32(a) && is_valid_u32(b) ==> 
      (a | b) == (b | a); */

/*@ requires is_valid_u32(a) && is_valid_u32(b);
    ensures \result == ((a | b) == (b | a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    //@ assert is_valid_u32(a);
    //@ assert is_valid_u32(b);
    return (a | b) == (b | a);
}
