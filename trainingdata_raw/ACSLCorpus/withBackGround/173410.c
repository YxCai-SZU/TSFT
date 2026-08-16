#include <stdbool.h>

/*@ predicate is_valid_index(integer i, integer len) =
      0 <= i && i < len;
*/

/*@ predicate is_valid_value(integer v) =
      1 <= v && v <= 9;
*/

/*@ predicate all_valid(int *arr, integer len) =
      \forall integer i; is_valid_index(i, len) ==> is_valid_value(arr[i]);
*/

/*@ predicate is_increasing(int *arr) =
      arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
  requires \valid(arr + (0 .. 2));
  requires all_valid(arr, 3);
  ensures \result == 1 <==> is_increasing(arr);
*/
bool is_increasing_sequence(int *arr) {
    int a;
    int b;
    int c;
    
    a = arr[0];
    b = arr[1];
    c = arr[2];
    
    //@ assert is_valid_value(a) && is_valid_value(b) && is_valid_value(c);
    
    return a < b && b < c;
}
