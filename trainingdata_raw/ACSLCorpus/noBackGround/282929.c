#include <stdbool.h>
#include <stdint.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, int32_t *numbers) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] > 0 && numbers[j] <= 1000;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int32_t x = numbers[i];
        
        //@ assert x > 0 && x <= 1000;
        
        if (x % 2 == 0) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
