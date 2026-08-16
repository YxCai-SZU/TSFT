#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint32_t *a) {
    uint64_t result = 0;
    uint64_t acc = 0;
    uint64_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= result <= index;
        loop invariant 0 <= acc <= index * 1000000;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000);
        loop assigns result, acc, index;
        loop variant n - index;
    */
    while (index < n) {
        uint32_t value = a[index];
        
        //@ assert 1 <= value <= 1000000;
        
        if (acc % 2 == 0) {
            if (value % 2 == 1) {
                result += 1;
            }
        }
        
        acc += (uint64_t)value;
        index += 1;
        
        //@ assert acc <= index * 1000000;
    }
    
    //@ assert result <= n;
    return result;
}
