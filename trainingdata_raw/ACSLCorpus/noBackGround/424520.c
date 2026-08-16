#include <stdbool.h>
#include <stdint.h>

/*@ requires 1 <= N <= 100;
    requires 0 <= A <= ((N) * (N));
    ensures \result == ((N) * (N)) - A;
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t A) {
    int32_t result;
    //@ assert 0 <= ((N) * (N)) <= 10000;
    result = N * N - A;
    return result;
}

/*@ requires \valid(arr + (0..len-1));
    requires len > 0;
    ensures \forall integer i; 0 <= i < len ==> \result <= arr[i];
    assigns \nothing;
*/
uint32_t min_element(const uint32_t* arr, uint32_t len) {
    uint32_t min_val;
    uint32_t idx;
    
    min_val = arr[0];
    
    /*@ loop invariant 1 <= idx <= len;
        loop invariant \forall integer k; 0 <= k < idx ==> min_val <= arr[k];
        loop assigns min_val, idx;
    */
    for (idx = 1; idx < len; idx++) {
        if (arr[idx] < min_val) {
            min_val = arr[idx];
        }
    }
    return min_val;
}
