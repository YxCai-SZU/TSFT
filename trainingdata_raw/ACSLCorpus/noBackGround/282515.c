#include <stdbool.h>

/*@
  requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
      1 <= (v)[0] && (v)[0] <= 100 &&
      1 <= (v)[1] && (v)[1] <= 100 &&
      1 <= (v)[2] && (v)[2] <= 100);
  ensures (v[0] + v[1] >= v[2] && \result == 1) ||
          (v[0] + v[1] < v[2] && \result == 0);
*/
int func(int *v) {
    int result;
    
    if (v[0] + v[1] >= v[2]) {
        //@ assert v[0] + v[1] >= v[2];
        result = 1;
    } else {
        //@ assert v[0] + v[1] < v[2];
        result = 0;
    }
    
    return result;
}
