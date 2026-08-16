#include <stdint.h>

/*@ predicate positive(uint32_t x) = x > 0; */

/*@ predicate multiplication_safe(uint32_t l, uint32_t b) = 
      (uint64_t)l * (uint64_t)l + (uint64_t)b * (uint64_t)b <= UINT32_MAX; */

/*@ logic integer square(integer x) = x * x; */

/*@ logic integer diagonal_squared(integer l, integer b) = 
      square(l) + square(b); */

/*@ lemma square_bounds: 
      \forall integer l, b; 
      l > 0 && b > 0 && 
      (uint64_t)l * (uint64_t)l + (uint64_t)b * (uint64_t)b <= UINT32_MAX ==> 
      (uint64_t)l * (uint64_t)l <= UINT32_MAX && (uint64_t)b * (uint64_t)b <= UINT32_MAX; */

/*@ requires positive(l) && positive(b) && multiplication_safe(l, b);
    ensures \result == diagonal_squared(l, b);
    assigns \nothing;
*/
uint32_t rectangle_diagonal_squared(uint32_t l, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t l_squared;
    uint32_t b_squared;
    uint32_t sum_of_squares;
    
    //@ assert (uint64_t)l * (uint64_t)l <= UINT32_MAX;
    l_squared = l * l;
    
    //@ assert (uint64_t)b * (uint64_t)b <= UINT32_MAX;
    b_squared = b * b;
    
    sum_of_squares = l_squared + b_squared;
    return sum_of_squares;
}
