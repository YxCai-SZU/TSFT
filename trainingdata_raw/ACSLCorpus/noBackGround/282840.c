#include <limits.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    requires -100 <= D <= 100;
    ensures \result == A + B + C || \result == A + C + D || \result == B + C + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D) {
    int max_val;
    int temp_val;
    
    max_val = A + B + C;
    temp_val = A + C + D;
    
    //@ assert -300 <= max_val <= 300;
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert max_val == A + B + C || max_val == A + C + D;
    
    temp_val = B + C + D;
    
    //@ assert -300 <= temp_val <= 300;
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert max_val == A + B + C || max_val == A + C + D || max_val == B + C + D;
    
    return max_val;
}
