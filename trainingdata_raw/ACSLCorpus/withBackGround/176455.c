#include <stdbool.h>

/*@ predicate is_triangle(integer a, integer b, integer c) =
      a + b >= c && a + c >= b && b + c >= a;
*/

/*@
  requires \valid(a + (0..2));
  requires 1 <= a[0] <= 13;
  requires 1 <= a[1] <= 13;
  requires 1 <= a[2] <= 13;
  assigns \nothing;
  ensures \result == true <==> is_triangle(a[0], a[1], a[2]);
*/
bool func(int a[3]) {
    int a0, a1, a2;
    bool result;

    a0 = a[0];
    a1 = a[1];
    a2 = a[2];

    if (a1 + a2 < a0 || a0 + a2 < a1 || a0 + a1 < a2) {
        result = false;
    } else {
        //@ assert is_triangle(a0, a1, a2);
        result = true;
    }

    return result;
}
