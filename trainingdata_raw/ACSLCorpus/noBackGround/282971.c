#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires (1 <= (v[0]) <= 100);
  requires (1 <= (v[1]) <= 100);
  requires (1 <= (v[2]) <= 100);
  ensures \result == (v[1] - v[0] == v[2] - v[1]);
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    int diff1;
    int diff2;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == diff2 ==> (v[1] - v[0] == v[2] - v[1]);

    result = (diff1 == diff2);
    return result;
}
