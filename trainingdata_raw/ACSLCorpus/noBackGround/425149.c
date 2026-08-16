#include <stdbool.h>

/*@
  requires 1 <= A <= 100;
  requires 1 <= B <= 100;
  requires 1 <= C <= 100;
  ensures \result == true <==> ((A) + (B) + (C) >= 22);
*/
bool func(int A, int B, int C) {
    // Variable declarations at top of scope
    int sum;
    bool result;
    
    //@ assert A >= 1 && A <= 100;
    //@ assert B >= 1 && B <= 100;
    //@ assert C >= 1 && C <= 100;
    //@ assert A + B <= 200;
    //@ assert A + B + C <= 300;
    
    sum = A + B + C;
    
    if (sum >= 22) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
