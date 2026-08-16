#include <stdbool.h>

/*@
  requires 1 <= A <= 100;
  requires 1 <= B <= 100;
  requires 1 <= C <= 100;
  ensures \result == true <==> ((A) == (B) && (B) == (C));
*/
bool func(int A, int B, int C)
{
    bool result;
    
    //@ assert 1 <= A <= 100 && 1 <= B <= 100 && 1 <= C <= 100;
    
    if ((A == B) && (B == C)) {
        //@ assert ((A) == (B) && (B) == (C));
        result = true;
    } else {
        //@ assert !((A) == (B) && (B) == (C));
        result = false;
    }
    
    return result;
}
