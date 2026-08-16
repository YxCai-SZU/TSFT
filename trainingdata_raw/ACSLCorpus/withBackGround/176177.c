#include <stdbool.h>

/*@ predicate is_valid_input(integer a, integer b, integer c) =
      1 <= a && a <= 100 &&
      1 <= b && b <= 100 &&
      1 <= c && c <= 100;
*/

/*@ predicate all_equal(integer a, integer b, integer c) =
      a == b && b == c;
*/

/*@ predicate two_equal(integer a, integer b, integer c) =
      (a == b && b != c) ||
      (a != b && b == c) ||
      (a == c && b != c);
*/

/*@ predicate all_different(integer a, integer b, integer c) =
      a != b && b != c && a != c;
*/

/*@ lemma color_count_bounds:
      \forall integer a,b,c;
      is_valid_input(a,b,c) ==>
      (all_equal(a,b,c) ==> 1 == 1) &&
      (two_equal(a,b,c) ==> 2 == 2) &&
      (all_different(a,b,c) ==> 3 == 3);
*/

/*@
  requires is_valid_input(a,b,c);
  ensures \result >= 1 && \result <= 3;
  ensures all_equal(a,b,c) ==> \result == 1;
  ensures two_equal(a,b,c) ==> \result == 2;
  ensures all_different(a,b,c) ==> \result == 3;
*/
unsigned int count_unique_colors(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int num_colors;
    
    //@ assert is_valid_input(a,b,c);
    
    if (a == b) {
        if (b == c) {
            num_colors = 1;
        } else {
            num_colors = 2;
        }
    } else if (a == c) {
        num_colors = 2;
    } else if (b == c) {
        num_colors = 2;
    } else {
        num_colors = 3;
    }
    
    //@ assert all_equal(a,b,c) ==> num_colors == 1;
    //@ assert two_equal(a,b,c) ==> num_colors == 2;
    //@ assert all_different(a,b,c) ==> num_colors == 3;
    
    return num_colors;
}

int main() {
    return 0;
}
