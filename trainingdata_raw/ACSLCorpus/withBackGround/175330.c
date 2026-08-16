#include <stdint.h>

/*@ predicate bounds_xy(integer x, integer y) = 
      0 <= x <= 8 && 0 <= y <= 8; */

/*@ logic integer mul(integer x, integer y) = x * y; */

/*@ lemma mul_commutative: 
      \forall integer x, y; 
      x <= 8 && y <= 8 ==> mul(x, y) == mul(y, x); */

/*@ lemma mul_associative: 
      \forall integer x, y, z; 
      x <= 8 && y <= 8 && z <= 8 ==> 
      mul(x, mul(y, z)) == mul(mul(x, y), z); */

/*@ lemma mul_distributive_add: 
      \forall integer x, y, z; 
      x <= 8 && y <= 8 && z <= 8 ==> 
      mul(x, y + z) == mul(x, y) + mul(x, z); */

/*@ lemma nonlinear_inequality: 
      \forall integer x, y; 
      0 <= x <= 5 && 0 <= y <= 7 ==> mul(x, y) <= 35; */

/*@ lemma mul_bound_64: 
      \forall integer x, y; 
      bounds_xy(x, y) ==> mul(x, y) <= 64; */

/*@ requires bounds_xy(x, y);
    @ ensures \result == mul(x, y);
    @ assigns \nothing;
    @*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert bounds_xy(x, y);
    //@ assert mul(x, y) <= 64;
    return x * y;
}
