#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires ((N) >= 1 && (N) <= 200000 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] && (A)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0 && \result <= (int32_t)N;
*/
int32_t func(size_t N, uint32_t *A) {
    int32_t count = 0;
    uint32_t prev_height = 0;
    size_t i = 0;
    
    //@ assert ((N) >= 1 && (N) <= 200000 &&       \valid((A) + (0 .. (N)-1)) &&       \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] && (A)[i] <= 1000000000);
    
    /*@ loop invariant (0 <= (i) && (i) <= (N) &&
      0 <= (count) && (count) <= (int32_t)(i) &&
      (prev_height) <= 1000000000);
        loop assigns i, count, prev_height;
        loop variant N - i;
    */
    while (i < N) {
        uint32_t height = A[i];
        
        if (prev_height > height) {
            //@ assert prev_height > height;
            count += 1;
        } else {
            //@ assert prev_height <= height;
            prev_height = height;
        }
        
        i += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= (int32_t)N;
    return count;
}
