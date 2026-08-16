#include <stdint.h>

/*@ predicate valid_radius(integer r) = 1 <= r <= 100; */

/*@ logic integer calculate_circumference(integer r) = 2 * 3 * r; */

/*@ lemma bounds_check: 
      \forall integer r; valid_radius(r) ==> 
      2 * 3 * 1 <= calculate_circumference(r) <= 2 * 3 * 100; */

/*@
  requires valid_radius(r);
  ensures \result == calculate_circumference(r);
*/
int32_t func(int32_t r)
{
  int32_t pi_approx;
  int32_t circumference;
  
  pi_approx = 3;
  circumference = 2 * pi_approx * r;
  
  //@ assert circumference == calculate_circumference(r);
  
  return circumference;
}
