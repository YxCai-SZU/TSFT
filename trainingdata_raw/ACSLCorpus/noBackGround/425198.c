#include <stdbool.h>

/*@ requires \valid(v + (0..2));
    requires ((3) == 3 &&
      \forall integer i; (0 <= (i) && (i) < ((3))) ==> (1 <= ((v)[i]) && ((v)[i]) <= 100));
    assigns \nothing;
    ensures \result == true <==> (((v[0]) + (v[1]) == (v[2])) || ((v[0]) + (v[2]) == (v[1])) || ((v[1]) + (v[2]) == (v[0])));
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    
    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
