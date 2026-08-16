#include <stdbool.h>

/*@ requires \valid(v+(0..2));
    requires ((3) >= 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (v)[i] && (v)[i] <= 9);
    ensures \result == (v[1] * v[1] == v[2]);
*/
bool func(int* v) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= b * b && b * b <= 81;
    
    result = (b * b == c);
    
    //@ assert result == (v[1] * v[1] == v[2]);
    
    return result;
}
