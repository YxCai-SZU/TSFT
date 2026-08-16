#include <stdbool.h>

/*@ requires \valid(v + (0..1));
    requires ((2) == 2 &&
      1 <= (v)[0] && (v)[0] <= 100 &&
      0 <= (v)[1] && (v)[1] <= (v)[0]);
    ensures \result == (v[0] == v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    bool result;
    
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 0 && v[1] <= v[0];
    
    result = (v[0] == v[1]);
    return result;
}
