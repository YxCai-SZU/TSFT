#include <stdbool.h>

/*@ requires 0 <= A && A <= 100;
    requires 0 <= B && B <= 100;
    requires 0 <= C && C <= 100;
    requires ((A) != (B) && (B) != (C) && (A) != (C));
    ensures \result == ((A < C && C < B) || (A > C && C > B));
    assigns \nothing;
*/
bool func(long A, long B, long C) {
    bool result;
    
    // Main logic
    if ((A < C && C < B) || (A > C && C > B)) {
        result = true;
        //@ assert (((A) < (C) && (C) < (B)) || ((A) > (C) && (C) > (B)));
    } else {
        result = false;
        //@ assert !(((A) < (C) && (C) < (B)) || ((A) > (C) && (C) > (B)));
    }
    
    return result;
}
