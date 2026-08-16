#include <stdbool.h>

/*@
  requires \valid(v);
  requires (\valid((v)) &&
      (v)[0] >= 1 && (v)[0] <= 100 &&
      (v)[1] >= 1 && (v)[1] <= 100 &&
      (v)[2] >= 1 && (v)[2] <= 200);
  ensures \result == (v[0] <= v[2] && v[2] <= v[1] + v[0]);
*/
bool func(int *v) {
    //@ assert (\valid((v)) &&       (v)[0] >= 1 && (v)[0] <= 100 &&       (v)[1] >= 1 && (v)[1] <= 100 &&       (v)[2] >= 1 && (v)[2] <= 200);
    //@ assert ((3) == 3 ? 1 : 0) == 1;
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    //@ assert v[2] >= 1 && v[2] <= 200;
    return v[0] <= v[2] && v[2] <= v[1] + v[0];
}
