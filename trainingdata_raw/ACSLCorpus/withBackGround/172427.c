#include <stdbool.h>

/*@ predicate a_le_b(integer a, integer b) = a <= b; */

/*@ predicate c_in_range(integer c) = 
      -0x80000000 <= c <= 0x7FFFFFFF; */

/*@ predicate a_in_range(integer a) = 
      -0x80000000 <= a <= 0x7FFFFFFF; */

/*@ predicate b_in_range(integer b) = 
      -0x80000000 <= b <= 0x7FFFFFFF; */

/*@ lemma trivial_implication: 
      \forall integer a, b, c; 
        a <= c && c <= b ==> (a <= c && c <= b); */

/*@
  requires a_le_b(a, b);
  requires a_in_range(a);
  requires b_in_range(b);
  requires c_in_range(c);
  ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert a <= c && c <= b ==> (a <= c && c <= b);
    
    if (a <= c && c <= b) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
