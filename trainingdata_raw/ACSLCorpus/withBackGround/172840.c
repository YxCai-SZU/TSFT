#include <stdint.h>

/*@ predicate in_range(integer a, integer b) = 
      1 <= a <= 100 && 1 <= b <= 100; */

/*@ logic integer safe_mult(integer a, integer b) = a * b; */

/*@ lemma mult_bounds: 
      \forall integer a, b; 
      in_range(a, b) ==> safe_mult(a, b) <= 10000; */

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert in_range(a, b);
    //@ assert a * b <= 10000;
    return a * b;
}
