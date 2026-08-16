#include <stdbool.h>

/*@ predicate is_in_range(int* arr, integer len) =
      \forall integer i; 0 <= i < len ==> -100 <= arr[i] && arr[i] <= 100;
*/

/*@ predicate is_increasing(int* arr, integer len) =
      len == 3 && arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
  requires \valid(ss + (0..2));
  requires is_in_range(ss, 3);
  ensures \result ==> is_increasing(ss, 3);
  ensures !\result ==> !is_increasing(ss, 3);
*/
bool is_increasing_sequence(int* ss) {
    //@ assert \valid(ss + (0..2));
    //@ assert is_in_range(ss, 3);
    return ss[0] < ss[1] && ss[1] < ss[2];
}

int main() {
    return 0;
}
