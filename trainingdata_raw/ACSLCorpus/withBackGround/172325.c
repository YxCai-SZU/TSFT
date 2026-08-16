#include <stdbool.h>

/*@ predicate all_equal(integer a, integer b, integer c) = 
      a == b && b == c;
*/
/*@ predicate two_equal(integer a, integer b, integer c) = 
      (a == b && b != c) || 
      (b == c && a != b) || 
      (a == c && a != b);
*/
/*@ predicate all_different(integer a, integer b, integer c) = 
      a != b && b != c && a != c;
*/

/*@
  requires \valid_read(input + (0..2));
  requires 1 <= input[0] <= 100;
  requires 1 <= input[1] <= 100;
  requires 1 <= input[2] <= 100;
  ensures \result >= 1 && \result <= 3;
  ensures \result == 1 ==> all_equal(input[0], input[1], input[2]);
  ensures \result == 2 ==> two_equal(input[0], input[1], input[2]);
  ensures \result == 3 ==> all_different(input[0], input[1], input[2]);
*/
int func(const int input[3]) {
    int a;
    int b;
    int c;
    int result;

    a = input[0];
    b = input[1];
    c = input[2];

    if (a == b && b == c) {
        //@ assert all_equal(a, b, c);
        result = 1;
    } else if (a == b || b == c || c == a) {
        //@ assert two_equal(a, b, c);
        result = 2;
    } else {
        //@ assert all_different(a, b, c);
        result = 3;
    }

    return result;
}
