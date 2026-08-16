#include <limits.h>

/*@
    predicate in_range(integer a) = -1000000000 <= a <= 1000000000;
    predicate product_in_range(integer a, integer b) = 
        -1000000000000000000 <= a * b <= 1000000000000000000;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    requires A <= B && C <= D;
    requires product_in_range(A, C) && product_in_range(A, D) && 
             product_in_range(B, C) && product_in_range(B, D);
    ensures \result == A * C || \result == A * D || 
            \result == B * C || \result == B * D;
    ensures \result >= A * C && \result >= A * D && 
            \result >= B * C && \result >= B * D;
*/
long long func(long long A, long long B, long long C, long long D) {
    long long max_val;
    long long temp_val;
    
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    //@ assert in_range(D);
    //@ assert product_in_range(A, C);
    //@ assert product_in_range(A, D);
    
    max_val = A * C;
    temp_val = A * D;
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = B * C;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = B * D;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    return max_val;
}
