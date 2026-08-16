#include <stdbool.h>

/*@
  requires \valid_read(a + (0..2));
  requires (1 <= (a[0]) && (a[0]) <= 100) && (1 <= (a[1]) && (a[1]) <= 100) && (1 <= (a[2]) && (a[2]) <= 100);
  ensures \result == (a[1] - a[0] == a[2] - a[1]);
  assigns \nothing;
*/
bool func(const int a[3]) {
    int a_0;
    int a_1;
    int a_2;
    bool result;

    a_0 = a[0];
    a_1 = a[1];
    a_2 = a[2];

    //@ assert (1 <= (a_0) && (a_0) <= 100);
    //@ assert (1 <= (a_1) && (a_1) <= 100);
    //@ assert (1 <= (a_2) && (a_2) <= 100);

    result = (a_1 - a_0 == a_2 - a_1);
    return result;
}
