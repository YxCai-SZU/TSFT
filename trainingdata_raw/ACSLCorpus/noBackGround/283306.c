#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires ((3) >= 3 &&
      (v)[0] >= 1 && (v)[0] <= 9 &&
      (v)[1] >= 1 && (v)[1] <= 9 &&
      (v)[2] >= 1 && (v)[2] <= 9);
  ensures \result == 1 <==> ((v)[0] < (v)[1] && (v)[1] < (v)[2]);
  assigns \nothing;
*/
bool func(int *v) {
    int v0, v1, v2;
    
    v0 = v[0];
    v1 = v[1];
    v2 = v[2];
    
    //@ assert v0 >= 1 && v0 <= 9;
    //@ assert v1 >= 1 && v1 <= 9;
    //@ assert v2 >= 1 && v2 <= 9;
    
    return v0 < v1 && v1 < v2;
}
