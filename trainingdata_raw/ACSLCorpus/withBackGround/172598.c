#include <stdbool.h>

/*@ predicate valid_input(integer s0, integer s1, integer s2) =
      s0 >= 1 && s0 <= 100 &&
      s1 >= 1 && s1 <= 100 &&
      s2 >= 1 && s2 <= 200;
*/

/*@ logic integer sum(integer a, integer b) = a + b; */

/*@ lemma sum_bound: 
      \forall integer s0, s1; 
      s0 >= 1 && s0 <= 100 && s1 >= 1 && s1 <= 100 ==> sum(s0, s1) <= 200;
*/

/*@
  requires \valid_read(s + (0..2));
  requires s[0] >= 1 && s[0] <= 100;
  requires s[1] >= 1 && s[1] <= 100;
  requires s[2] >= 1 && s[2] <= 200;
  assigns \nothing;
  ensures \result == (s[0] <= s[2] && s[0] + s[1] >= s[2]);
*/
bool func(const unsigned int s[3]) {
    //@ assert s[0] + s[1] <= 200;
    return s[0] <= s[2] && s[0] + s[1] >= s[2];
}
