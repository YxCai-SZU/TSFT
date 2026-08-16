#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (n) <= 100000);
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int32_t func(int32_t n, int32_t *numbers) {
    int32_t count = 0;
    int32_t index = 0;
    
    /*@ loop invariant (0 <= (index) <= (n) && 0 <= (count) <= (index));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop invariant \valid(numbers + (0 .. n-1));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int32_t tmp = numbers[index];
        bool is_divisible = true;
        
        /*@ loop invariant 0 <= tmp <= 1000000000;
            loop assigns tmp;
            loop variant tmp;
        */
        while (tmp >= 2) {
            tmp = tmp - 1;
        }
        
        if (tmp != 0) {
            is_divisible = false;
        }
        
        if (is_divisible) {
            count = count + 1;
        }
        
        index = index + 1;
    }
    
    return count;
}

