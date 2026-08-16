#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    predicate condition_holds(integer A, integer B, integer C, integer D) =
        D <= B || (A <= C && C <= B) || (A <= D && D <= C);
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C) && valid_range(D);
    ensures \result == true <==> condition_holds(A, B, C, D);
    assigns \nothing;
*/
bool func(int A, int B, int C, int D)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    //@ assert valid_range(D);
    
    if (D <= B) {
        //@ assert condition_holds(A, B, C, D);
        result = true;
        return result;
    }
    
    if (A <= C && C <= B) {
        //@ assert condition_holds(A, B, C, D);
        result = true;
        return result;
    }
    
    if (A <= D && D <= C) {
        //@ assert condition_holds(A, B, C, D);
        result = true;
        return result;
    }
    
    //@ assert !condition_holds(A, B, C, D);
    result = false;
    return result;
}
