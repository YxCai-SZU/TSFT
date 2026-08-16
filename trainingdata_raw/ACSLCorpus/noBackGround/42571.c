#include <limits.h>

/*@
    requires (-1000000000 <= (A) <= 1000000000) && (-1000000000 <= (B) <= 1000000000) && (-1000000000 <= (C) <= 1000000000) && (-1000000000 <= (D) <= 1000000000);
    requires A <= B && C <= D;
    ensures \result == B * D || \result == B * C || \result == A * D || \result == A * C;
*/
long long func(long long A, long long B, long long C, long long D) {
    long long max_val;
    long long temp_val;
    
    //@ assert (-1000000000000000000 <= (A) * (C) <= 1000000000000000000);
    max_val = A * C;
    
    //@ assert (-1000000000000000000 <= (A) * (D) <= 1000000000000000000);
    temp_val = A * D;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert (-1000000000000000000 <= (B) * (C) <= 1000000000000000000);
    temp_val = B * C;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert (-1000000000000000000 <= (B) * (D) <= 1000000000000000000);
    temp_val = B * D;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    return max_val;
}
