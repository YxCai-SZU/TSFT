#include <stdbool.h>

/*@
  requires \valid(v + (0..5));
  requires \forall integer i; 0 <= i < 6 ==> ((v[i]) == 0 || (v[i]) == 1);
  ensures \result == true;
*/
bool func(int v[6]) {
    int x;
    x = v[4];
    
    if (v[0] == 1) {
        x = v[4] - 1;
    }
    if (v[1] == 1) {
        x = v[4] - 2;
    }
    if (v[2] == 1) {
        x = v[4] - 3;
    }
    if (v[3] == 1) {
        x = v[4] - 4;
    }
    if (x < 0) {
    }
    
    //@ assert ((v[4]) == 0 || (v[4]) == 1);
    
    return true;
}
