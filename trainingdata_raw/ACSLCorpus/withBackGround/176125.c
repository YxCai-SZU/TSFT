#include <stdbool.h>
#include <stdint.h>

/*@ predicate non_negative(integer a, integer b, integer c) =
      a >= 0 && b >= 0 && c >= 0;
*/

/*@ predicate sum_within_limit(integer a, integer b, integer c) =
      a + b + c <= 1000000000000;
*/

/*@ predicate is_arithmetic_sequence(integer a, integer b, integer c) =
      b - a == c - b;
*/

/*@ lemma arithmetic_sequence_property:
      \forall integer a, b, c;
        non_negative(a, b, c) && sum_within_limit(a, b, c) ==>
        (is_arithmetic_sequence(a, b, c) ==> b - a == c - b);
*/

/*@
  requires \valid_read(v + (0..2));
  requires non_negative(v[0], v[1], v[2]);
  requires sum_within_limit(v[0], v[1], v[2]);
  ensures \result == (v[1] - v[0] == v[2] - v[1]);
*/
bool func(const int64_t v[3]) {
    bool result;
    
    //@ assert non_negative(v[0], v[1], v[2]);
    
    result = (v[1] - v[0] == v[2] - v[1]);
    
    //@ assert result == (v[1] - v[0] == v[2] - v[1]);
    return result;
}
