#include <stdbool.h>
#include <stdint.h>

/*@ requires (2 <= (n) && (n) <= 200000);
    requires ((len) == (n));
    requires (\forall integer k; 0 <= k < (len) ==> (1 <= ((numbers)[k]) && ((numbers)[k]) <= 1000000000));
    requires \valid_read(numbers + (0 .. len-1));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
 */
uint64_t func(uint64_t n, uint64_t *numbers, uint64_t len) {
    uint64_t min = 1000000;
    uint64_t count = 0;
    uint64_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant min >= 0;
        loop invariant (\forall integer k; 0 <= k < (len) ==> (1 <= ((numbers)[k]) && ((numbers)[k]) <= 1000000000));
        loop assigns i, count, min;
        loop variant len - i;
     */
    while (i < len) {
        uint64_t a = numbers[i];
        bool is_divisible = false;
        uint64_t temp_min = min;
        
        /*@ loop invariant temp_min >= 0;
            loop invariant temp_min <= min;
            loop assigns temp_min, is_divisible;
            loop variant temp_min;
         */
        while (temp_min > 0) {
            uint64_t remainder = a;
            
            /*@ loop invariant remainder >= 0;
                loop assigns remainder;
                loop variant remainder;
             */
            while (remainder >= temp_min) {
                remainder -= temp_min;
            }
            
            if (remainder == 0) {
                is_divisible = true;
                break;
            }
            temp_min -= 1;
        }
        
        if (is_divisible) {
            count += 1;
            min = temp_min;
        }
        i += 1;
    }
    return count;
}
