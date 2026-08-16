#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x && x <= 100; */

/*@
  requires \valid_read(a + (0..2));
  requires is_valid_range(a[0]) && is_valid_range(a[1]) && is_valid_range(a[2]);
  ensures \result == (a[1] - a[0] == a[2] - a[1]);
*/
bool func(const int *a) {
    int a0;
    int a1;
    int a2;
    int b;
    int c;
    bool result;

    a0 = a[0];
    a1 = a[1];
    a2 = a[2];

    b = a1 - a0;
    //@ assert b == a1 - a0;

    c = a2 - a1;
    //@ assert c == a2 - a1;

    result = (b == c);
    return result;
}
