#include <stdint.h>
#include <stdbool.h>

/*@ requires ((n) >= 1 && (n) <= 200000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= (n) &&
    \forall integer i, j; 0 <= i < j < (n) ==> (numbers)[i] != (numbers)[j]);
    assigns \nothing;
    ensures 1 <= \result <= n;
*/
int32_t func(uint32_t n, uint32_t *numbers) {
    uint32_t target = 1;
    int32_t count = 1;
    uint32_t index = 1;
    
    /*@ loop invariant (1 <= (index) <= (n) &&
    1 <= (target) <= (index) &&
    1 <= (count) <= (index) &&
    \forall integer i; 0 <= i < (index) ==> (numbers)[i] >= 1 && (numbers)[i] <= (n) &&
    \forall integer i, j; 0 <= i < j < (n) ==> (numbers)[i] != (numbers)[j]);
        loop assigns target, count, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 1 <= count <= index;
        if (numbers[index] == target) {
            target += 1;
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 1;
    return count;
}
