#include <stdbool.h>

/*@
  requires \valid(x + (0..1));
  requires ((x[0]) == 0 || (x[0]) == 1) && ((x[1]) == 0 || (x[1]) == 1);
  ensures \result == (x[0] == 1 && x[1] == 2 || x[0] == 1 && x[1] == 3 || 
                     x[0] == 2 && x[1] == 1 || x[0] == 3 && x[1] == 1 || 
                     x[0] == 1 && x[1] == 4 || x[0] == 4 && x[1] == 1);
*/
bool func(int *x) {
    int x0;
    int x1;
    bool result;

    x0 = x[0];
    x1 = x[1];

    //@ assert x0 == 0 || x0 == 1;
    //@ assert x1 == 0 || x1 == 1;

    result = (x0 == 1 && x1 == 2 || x0 == 1 && x1 == 3 || 
              x0 == 2 && x1 == 1 || x0 == 3 && x1 == 1 || 
              x0 == 1 && x1 == 4 || x0 == 4 && x1 == 1);
    
    return result;
}
