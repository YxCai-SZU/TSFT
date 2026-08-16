#include <stddef.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 3; */
/*@ predicate distinct(integer a, integer b) = a != b; */
/*@ logic integer compute_result(integer a, integer b) = 6 - a - b; */

/*@ lemma result_in_range: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) && distinct(a,b) ==> 
      1 <= compute_result(a,b) <= 3; */

/*@
  requires 1 <= a <= 3;
  requires 1 <= b <= 3;
  requires a != b;
  ensures \result == 6 - a - b;
  ensures 1 <= \result <= 3;
*/
size_t func(size_t a, size_t b) {
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert distinct(a,b);
    
    size_t result = 6 - a - b;
    
    //@ assert result == compute_result(a,b);
    //@ assert 1 <= result <= 3;
    
    return result;
}
