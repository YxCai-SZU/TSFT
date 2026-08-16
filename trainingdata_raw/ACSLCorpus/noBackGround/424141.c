#include <stdbool.h>

/*@
  requires \valid(v+(0..1));
  requires v[0] >= 1 && v[0] < v[1] && v[1] <= 10000;
  ensures \result == true <==> ((v[1]) - (v[0]) >= 2 || (v[0]) == 1);
*/
bool func(int v[2]) {
    int diff;
    bool result;

    diff = v[1] - v[0];
    if (diff >= 2 || v[0] == 1) {
        result = true;
    } else {
        //@ assert diff < 2 && v[0] != 1;
        result = false;
    }
    return result;
}
