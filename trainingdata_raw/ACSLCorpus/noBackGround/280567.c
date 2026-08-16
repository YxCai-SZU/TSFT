#include <stdbool.h>

/*@
  requires (\valid((x)) && \valid((x)+1)) && (\valid((y)) && \valid((y)+1));
  requires (-10000 < (x[0]) < 10000) && (-10000 < (x[1]) < 10000);
  requires (-10000 < (y[0]) < 10000) && (-10000 < (y[1]) < 10000);
  ensures \result == (x[0] <= y[1] && y[0] <= x[1]);
*/
bool func(int *x, int *y) {
    bool result;
    
    //@ assert (\valid((x)) && \valid((x)+1));
    //@ assert (\valid((y)) && \valid((y)+1));
    //@ assert (-10000 < (x[0]) < 10000);
    //@ assert (-10000 < (x[1]) < 10000);
    //@ assert (-10000 < (y[0]) < 10000);
    //@ assert (-10000 < (y[1]) < 10000);
    
    result = (x[0] <= y[1] && y[0] <= x[1]);
    return result;
}
