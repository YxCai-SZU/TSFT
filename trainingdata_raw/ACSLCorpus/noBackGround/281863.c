#include <stdbool.h>

/*@
  requires \valid(v + (0..2));
  requires ((3) == 3 &&
      (v)[0] >= -100 &&
      (v)[1] <= 100 &&
      ((-100) <= ((v)[2]) && ((v)[2]) <= (100)) &&
      (v)[0] <= (v)[1]);
  ensures ((\result) <==> ((v)[2] >= (v)[0] && (v)[2] <= (v)[1]));
*/
bool func(long *v) {
    bool result;
    
    //@ assert v[0] >= -100;
    //@ assert v[1] <= 100;
    //@ assert ((-100) <= (v[2]) && (v[2]) <= (100));
    //@ assert v[0] <= v[1];
    
    if (v[2] >= v[0] && v[2] <= v[1]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
