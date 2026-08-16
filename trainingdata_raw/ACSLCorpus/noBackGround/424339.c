#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires ((n) >= 1 && (n) <= 200000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= (int32_t)n - 1;
*/
int32_t func(size_t n, uint32_t *a) {
    int32_t counter = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= counter <= (int32_t)index;
        loop invariant index > 0 ==> ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> 
        ((a)[i] == (uint32_t)(i + 1) ==> (counter) > 0));
        loop invariant ((n) >= 1 && (n) <= 200000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
        loop assigns index, counter;
        loop variant n - index;
    */
    while (index < n) {
        uint32_t i = a[index];
        if (i == (uint32_t)(index + 1)) {
            counter += 1;
        }
        index += 1;
    }
    
    int32_t result;
    if (counter != 0) {
        result = counter - 1;
    } else {
        result = -1;
    }
    
    //@ assert result >= -1;
    //@ assert result <= (int32_t)n - 1;
    return result;
}
