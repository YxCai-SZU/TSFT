/*@
predicate less_than(integer a, integer b) = a < b;
predicate greater_than(integer a, integer b) = a > b;

lemma calc_example_6: \forall integer x, y; x < y ==> x + 2 < y + 3;
lemma calc_example_7: \forall integer x, y; x > y ==> x - 2 > y - 3;
lemma calc_example_8: \forall integer x, y; x < y ==> x + 2 < y + 3;
lemma calc_example_9: \forall integer x, y; x > y ==> x - 2 > y - 3;
*/

#include <stdbool.h>

/*@
  requires x < y;
  ensures \result == true;
*/
bool verify_calc_example_6(int x, int y) {
    //@ assert x < y;
    //@ assert x < y + 3;
    //@ assert x + 2 < y + 3;
    return true;
}

/*@
  requires x > y;
  ensures \result == true;
*/
bool verify_calc_example_7(int x, int y) {
    //@ assert x > y;
    //@ assert x > y - 3;
    //@ assert x - 2 > y - 3;
    return true;
}

/*@
  requires x < y;
  ensures \result == true;
*/
bool verify_calc_example_8(int x, int y) {
    //@ assert x < y;
    //@ assert x < y + 3;
    //@ assert x + 2 < y + 3;
    return true;
}

/*@
  requires x > y;
  ensures \result == true;
*/
bool verify_calc_example_9(int x, int y) {
    //@ assert x > y;
    //@ assert x > y - 3;
    //@ assert x - 2 > y - 3;
    return true;
}

int main() {
    return 0;
}
