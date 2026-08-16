#include <limits.h>

/*@
    requires (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000) && (-1000 <= (C) <= 1000) && (-1000 <= (D) <= 1000);
    ensures \result == A * C || \result == A * D || \result == B * C || \result == B * D;
    ensures \result >= A * C && \result >= A * D && \result >= B * C && \result >= B * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int max_val;
    
    //@ assert (-1000000 <= (A) * (C) <= 1000000);
    max_val = A * C;
    
    //@ assert (-1000000 <= (A) * (D) <= 1000000);
    if (A * D > max_val) {
        max_val = A * D;
    }
    
    //@ assert (-1000000 <= (B) * (C) <= 1000000);
    if (B * C > max_val) {
        max_val = B * C;
    }
    
    //@ assert (-1000000 <= (B) * (D) <= 1000000);
    if (B * D > max_val) {
        max_val = B * D;
    }
    
    return max_val;
}
