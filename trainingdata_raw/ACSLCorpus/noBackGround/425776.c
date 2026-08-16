#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires ((N) >= 1 && (N) <= 100 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= 100);
    ensures \result >= 0 && \result <= (int)N;
    assigns \nothing;
*/
int func(size_t N, const int64_t *A) {
    int ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (N) &&
        (ans) >= 0 &&
        (ans) <= (int)(i) &&
        \forall integer j; 0 <= j < (i) ==> (A)[j] >= 1 && (A)[j] <= 100);
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N) {
        int64_t index = A[i];
        
        if ((i + 1) % 2 == 0) {
            // ans += 0; // No operation needed
        } else {
            if (index & 1) {
                ans += 1;
            }
        }
        
        //@ assert ans >= 0;
        //@ assert ans <= (int)(i + 1);
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= (int)N;
    return ans;
}
