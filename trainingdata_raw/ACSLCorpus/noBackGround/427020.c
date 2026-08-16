#include <stdint.h>
#include <stdbool.h>

/*@ requires \valid(numbers + (0..len-1));
    requires len < 0x100000000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer k; 0 <= k < len ==> 
            ((((numbers[k]) & 1) != 0) ==> \result > 0);
 */
uint32_t filter_even(int32_t* numbers, uint32_t len) {
    uint32_t odd_count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= odd_count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> 
                      ((((numbers[k]) & 1) != 0) ==> odd_count > 0);
        loop assigns i, odd_count;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((numbers[i] & 1) != 0) {
            odd_count = odd_count + 1;
        }
        i = i + 1;
    }
    
    //@ assert odd_count <= len;
    return odd_count;
}
