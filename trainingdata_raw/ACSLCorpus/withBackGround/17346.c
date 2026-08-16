#include <stdbool.h>

/*@ predicate is_within_bounds(integer x) = 0 <= x <= 100; */
/*@ predicate are_distinct(integer x, integer y, integer z) = 
      x != y && y != z && x != z; */
/*@ predicate ordering_condition(integer a, integer b, integer c) = 
      (a <= c && c <= b) || (a >= c && c >= b); */

/*@
  requires is_within_bounds(a) && is_within_bounds(b) && is_within_bounds(c);
  requires are_distinct(a, b, c);
  ensures \result == 1 <==> ordering_condition(a, b, c);
*/
bool func(int a, int b, int c) {
    // Variable declarations at top of scope
    bool result;
    
    // Proof assertions
    //@ assert is_within_bounds(a);
    //@ assert is_within_bounds(b);
    //@ assert is_within_bounds(c);
    //@ assert are_distinct(a, b, c);
    
    result = (a <= c && c <= b) || (a >= c && c >= b);
    return result;
}
