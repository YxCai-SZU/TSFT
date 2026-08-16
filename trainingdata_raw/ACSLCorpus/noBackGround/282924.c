#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires (1 <= (v[0]) && (v[0]) <= 5000) && (1 <= (v[1]) && (v[1]) <= 5000) && (1 <= (v[2]) && (v[2]) <= 5000);
  ensures \result == (v[1] - v[0] == v[2] - v[1]);
  assigns \nothing;
*/
bool func(int v[3]) {
    int diff1;
    int diff2;
    bool result;

    //@ assert v[1] - v[0] >= -4999 && v[1] - v[0] <= 4999;
    //@ assert v[2] - v[1] >= -4999 && v[2] - v[1] <= 4999;

    diff1 = v[1] - v[0];
    diff2 = v[2] - v[1];

    if (diff1 == diff2) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
