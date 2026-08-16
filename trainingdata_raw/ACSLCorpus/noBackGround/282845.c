#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 3 &&
        \valid((A) + (0 .. (len)-1)) &&
        1 <= (A)[0] <= 100 &&
        1 <= (A)[1] <= 100 &&
        1 <= (A)[2] <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int *A, size_t len) {
    int min;
    int count;
    
    min = A[0];
    count = 1;
    
    //@ assert min == A[0] && count == 1;
    
    if (A[1] < min) {
        min = A[1];
        count = 1;
        //@ assert min == A[1] && count == 1;
    } else if (A[1] == min) {
        count += 1;
        //@ assert min == A[0] && count == 2;
    }
    //@ assert count >= 1 && count <= 2;
    
    if (A[2] < min) {
        min = A[2];
        count = 1;
        //@ assert min == A[2] && count == 1;
    } else if (A[2] == min) {
        count += 1;
        //@ assert count >= 2 && count <= 3;
    }
    
    //@ assert count >= 1;
    //@ assert count <= 3;
    
    return count;
}
