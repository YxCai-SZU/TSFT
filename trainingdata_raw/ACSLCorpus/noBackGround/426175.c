#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires N > 0 && N <= 200000;
    requires M > 0 && M <= 200000;
    requires \valid(A + (0..N-1));
    requires \valid(B + (0..M-1));
    requires ((N) > 0 && (N) <= 200000 &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= 1000000000);
    requires ((M) > 0 && (M) <= 200000 &&
      \forall integer i; 0 <= i < (M) ==> 1 <= (B)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= M;
*/
int64_t func(size_t N, const int64_t *A, size_t M, const int64_t *B) {
    int64_t ans = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= M;
        loop invariant ((ans) >= 0 && (ans) <= (i));
        loop assigns ans, i;
        loop variant M - i;
    */
    while (i < M) {
        int64_t b = B[i];
        size_t j = 0;
        bool found = false;
        
        /*@ loop invariant 0 <= j <= N;
            loop invariant !found ==> ans == \at(ans, LoopEntry);
            loop invariant found ==> ans == \at(ans, LoopEntry) + 1;
            loop invariant found ==> \exists integer k; 0 <= k < j && A[k] == b;
            loop invariant !found ==> \forall integer k; 0 <= k < j ==> A[k] != b;
            loop assigns j, found, ans;
            loop variant N - j;
        */
        while (j < N && !found) {
            if (A[j] == b) {
                ans += 1;
                found = true;
            }
            j += 1;
        }
        
        i += 1;
        //@ assert ((ans) >= 0 && (ans) <= (i));
    }
    
    return ans;
}
