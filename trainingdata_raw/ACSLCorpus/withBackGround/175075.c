#include <stdbool.h>

/*@ predicate is_valid_element(integer x) = x == 1 || x == 2 || x == 3; */
/*@ predicate is_sorted(integer a, integer b, integer c) = a < b && b < c; */

/*@
  requires \valid_read(arr + (0 .. 2));
  requires \forall integer i; 0 <= i < 3 ==> is_valid_element(arr[i]);
  ensures \result == 1 <==> is_sorted(arr[0], arr[1], arr[2]);
  assigns \nothing;
*/
bool func(int *arr) {
    int a;
    int b;
    int c;
    int i;
    int x;
    bool result;

    i = 0;
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant \forall integer j; 0 <= j < i ==> is_valid_element(arr[j]);
      loop assigns i, x;
      loop variant 3 - i;
    */
    while (i < 3) {
        x = arr[i];
        //@ assert is_valid_element(x);
        i = i + 1;
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];

    result = (a < b && b < c);
    //@ assert result == (a < b && b < c);
    return result;
}
