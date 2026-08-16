#include <stdbool.h>
#include <stdint.h>

/*@ requires N >= 1 && N <= 100;
    requires \valid(A + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> A[i] >= 1 && A[i] <= 100;
    ensures \result >= 0 && \result <= N;
*/
uint32_t func(uint32_t N, uint32_t *A) {
    uint32_t sum = 0;
    uint32_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (N) &&
      (sum) <= (i) &&
      (((N)) >= 1 && ((N)) <= 100 &&
      \valid(((A)) + (0 .. ((N))-1)) &&
      \forall integer i; 0 <= i < ((N)) ==> ((A))[i] >= 1 && ((A))[i] <= 100));
        loop assigns sum, i;
        loop variant N - i;
    */
    while (i < N) {
        uint32_t num = A[i];
        
        //@ assert i < N && num >= 1 && num <= 100;
        
        if ((i & 1) == 0 && (num & 1) == 1) {
            sum += 1;
        }
        
        i += 1;
    }
    
    //@ assert sum >= 0 && sum <= N;
    return sum;
}
