#include <stdbool.h>

/*@
  requires \valid(v + (0..3));
  requires (-100 <= (v[0]) && (v[0]) <= 100) && (-100 <= (v[1]) && (v[1]) <= 100) && 
           (-100 <= (v[2]) && (v[2]) <= 100) && (-100 <= (v[3]) && (v[3]) <= 100);
  ensures (v[0] == v[2] ==> \result == v[1] - v[3]) &&
          (v[0] != v[2] ==> \result == v[2] - v[1]);
*/
int func(int v[4]) {
    int result;
    
    //@ assert v[0] == v[2] || v[0] != v[2];
    
    if (v[0] == v[2]) {
        result = v[1] - v[3];
    } else {
        result = v[2] - v[1];
    }
    
    return result;
}
