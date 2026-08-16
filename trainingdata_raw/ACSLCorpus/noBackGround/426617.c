#include <stdbool.h>

/*@
  requires \valid(v + (0..2));
  requires (1 <= (v[0]) <= 100 &&
      1 <= (v[1]) <= 100 &&
      1 <= (v[2]) <= 200);
  ensures \result == 1 <==> ((v[1]) - (v[0]) == (v[2]) - (v[1]));
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert (1 <= (a) <= 100 &&       1 <= (b) <= 100 &&       1 <= (c) <= 200);

    if (b - a == c - b) {
        //@ assert ((b) - (a) == (c) - (b));
        result = true;
    } else {
        //@ assert !((b) - (a) == (c) - (b));
        result = false;
    }

    return result;
}
