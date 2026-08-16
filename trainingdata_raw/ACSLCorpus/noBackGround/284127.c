#include <stddef.h>
#include <stdint.h>

/*@ requires N >= 1 && N <= 100;
    requires \valid(A + (0 .. N-1));
    requires \forall size_t i; 0 <= i < N ==> A[i] >= 1 && A[i] <= 100;
    assigns \nothing;
    ensures \result >= 0 && \result <= (int32_t)N;
*/
int32_t func(size_t N, const int64_t *A) {
    int32_t count = 0;
    size_t num = 0;
    
    /*@ loop invariant 0 <= num <= N;
        loop invariant 0 <= count <= (int32_t)num;
        loop invariant ((N) >= 1 && (N) <= 100 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall size_t i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= 100);
        loop assigns count, num;
        loop variant N - num;
    */
    while (num < N) {
        int64_t value = A[num];
        
        //@ assert value >= 1 && value <= 100;
        
        if (((num + 1) & 1) != 0) {
            uint64_t value_unsigned = (value < 0) ? (uint64_t)(-value) : (uint64_t)value;
            
            if ((value_unsigned & 1) == 1) {
                //@ assert count >= 0 && count < (int32_t)(num + 1);
                count += 1;
                //@ assert count >= 1 && count <= (int32_t)(num + 1);
            }
        }
        
        num += 1;
        //@ assert count <= (int32_t)num;
    }
    
    //@ assert count <= (int32_t)N;
    return count;
}
