#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/*@ requires ((len) >= 1 && (len) <= 100 &&
    \forall integer i; 0 <= i < (len) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures \result >= 1 && \result <= 100;
    assigns \nothing;
*/
uint32_t func(int *numbers, uint32_t len) {
    uint32_t min = UINT32_MAX;
    uint32_t index = 0;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant index > 0 ==> min >= 1 && min <= 100;
        loop invariant \forall integer i; 0 <= i < index ==> min <= numbers[i];
        loop invariant index == 0 ==> min == UINT32_MAX;
        loop assigns min, index;
        loop variant len - index;
    */
    while (index < len) {
        uint32_t a = numbers[index];
        
        if (min > a) {
            min = a;
        }
        
        index = index + 1;
    }
    
    //@ assert min >= 1 && min <= 100;
    return min;
}
