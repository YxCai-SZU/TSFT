#include <stdint.h>

/*@
    requires 0 <= A && A <= 100;
    requires 0 <= P && P <= 100;
    ensures \result >= 0;
    ensures \result == (A * 3 + P) / 2;
*/
int32_t func(uint32_t A, uint32_t P) {
    uint32_t sum;
    uint32_t count;
    int32_t result;
    
    sum = A * 3 + P;
    count = 0;
    result = 0;
    
    /*@
        loop invariant 0 <= A && A <= 100;
        loop invariant 0 <= P && P <= 100;
        loop invariant sum >= 0;
        loop invariant sum == A * 3 + P - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= (A * 3 + P) / 2;
        loop invariant A * 3 + P == sum + 2 * count;
        loop assigns sum, count;
        loop variant sum;
    */
    while (sum >= 2) {
        //@ assert sum >= 2;
        sum -= 2;
        count += 1;
    }
    
    result = (int32_t)count;
    
    //@ assert result >= 0;
    //@ assert result == (A * 3 + P) / 2;
    
    return result;
}
