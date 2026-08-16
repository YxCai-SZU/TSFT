#include <stdbool.h>

/*@ requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
      1 <= (v)[0] && (v)[0] <= 100 &&
      1 <= (v)[1] && (v)[1] <= 100 &&
      1 <= (v)[2] && (v)[2] <= 100);
    ensures \result == (v[1] - v[0] == v[2] - v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    bool condition;
    
    //@ assert (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&       1 <= (v)[0] && (v)[0] <= 100 &&       1 <= (v)[1] && (v)[1] <= 100 &&       1 <= (v)[2] && (v)[2] <= 100);
    condition = (v[1] - v[0] == v[2] - v[1]);
    
    //@ assert condition == (v[1] - v[0] == v[2] - v[1]);
    
    return condition;
}
