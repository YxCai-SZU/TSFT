#include <stdbool.h>
#include <stdint.h>

/*@ requires ((N) >= 1 && (N) <= 100 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= 100);
    ensures ((\result) >= 0 && (\result) <= (N));
    assigns \nothing;
*/
int32_t func(int32_t N, int64_t *A) {
    int32_t ans = 0;
    int32_t i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (N) &&
      (ans) >= 0 && (ans) <= (i) &&
      \forall integer j; 0 <= j < (i) ==> (A)[j] >= 1 && (A)[j] <= 100 &&
      (N) >= 1 && (N) <= 100 &&
      \forall integer k; 0 <= k < (N) ==> (A)[k] >= 1 && (A)[k] <= 100);
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N) {
        int64_t value = A[i];
        //@ assert value >= 1 && value <= 100;
        
        if (((i & 1) == 0) && ((value & 1) == 1)) {
            ans += 1;
        }
        //@ assert ans >= 0 && ans <= i + 1;
        
        i += 1;
    }
    
    //@ assert i == N;
    return ans;
}
