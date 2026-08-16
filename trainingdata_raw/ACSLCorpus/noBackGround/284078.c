#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == ((((x)) / 500) * 1000 + (((((x)) % 500)) / 5) * 5);
*/
uint64_t func(uint64_t x) {
    uint64_t ans;
    uint64_t temp_x;
    uint64_t count_500;
    uint64_t count_5;
    
    ans = 0;
    temp_x = x;
    count_500 = 0;
    count_5 = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count_500 <= ((x) / 500);
        loop invariant temp_x == x - 500 * count_500;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns count_500, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        count_500 = count_500 + 1;
        temp_x = temp_x - 500;
        //@ assert temp_x == x - 500 * count_500;
    }
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count_5 <= ((x) / 5);
        loop invariant temp_x == x - 500 * count_500 - 5 * count_5;
        loop invariant (0 <= (x) <= 1000000000);
        loop assigns count_5, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        count_5 = count_5 + 1;
        temp_x = temp_x - 5;
        //@ assert temp_x == x - 500 * count_500 - 5 * count_5;
    }
    
    ans = count_500 * 1000 + count_5 * 5;
    
    //@ assert ans == ((((x)) / 500) * 1000 + (((((x)) % 500)) / 5) * 5);
    
    return ans;
}
