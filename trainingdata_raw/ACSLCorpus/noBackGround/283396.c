#include <stdbool.h>

/*@
    requires \valid(v + (0..1));
    requires ((2) == 2 &&
    0 <= (v)[0] <= 100 &&
    0 <= (v)[1] <= 100);
    ensures \result == (((v)[(0)]) <= ((v)[(1)]));
    assigns \nothing;
*/
bool func(int* v) {
    int x;
    int y;
    bool result;
    
    //@ assert v[0] == ((v)[(0)]);
    
    //@ assert v[1] == ((v)[(1)]);
    
    x = v[0];
    y = v[1];
    
    //@ assert x <= y ==> (x <= y) == true;
    
    //@ assert x > y ==> (x <= y) == false;
    
    result = x <= y;
    
    //@ assert result == (((v)[(0)]) <= ((v)[(1)]));
    
    return result;
}
