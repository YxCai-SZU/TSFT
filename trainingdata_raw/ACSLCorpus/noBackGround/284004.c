#include <stdbool.h>

/*@ requires \valid_read(v+(0..2));
    requires ((3) >= 3 &&
    \forall integer i; 0 <= i < 3 ==> 1 <= (v)[i] && (v)[i] <= 13);
    ensures \result == (v[2] <= v[0] + v[1]);
*/
bool func(int* v) {
    int a;
    int b;
    int c;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert v[2] == c;
    //@ assert v[0] == a;
    //@ assert v[1] == b;
    
    return c <= a + b;
}
