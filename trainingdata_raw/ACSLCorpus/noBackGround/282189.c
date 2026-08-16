#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t ans;
    uint64_t temp_x;
    uint64_t five_hundreds;
    uint64_t fives;
    
    ans = 0;
    temp_x = x;
    five_hundreds = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant five_hundreds <= ((x) / 500);
        loop invariant temp_x == x - five_hundreds * 500;
        loop assigns five_hundreds, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        five_hundreds = five_hundreds + 1;
        temp_x = temp_x - 500;
    }
    
    ans = five_hundreds * 1000;
    fives = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant fives <= (x - five_hundreds * 500) / 5;
        loop invariant temp_x == x - five_hundreds * 500 - fives * 5;
        loop assigns fives, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        fives = fives + 1;
        temp_x = temp_x - 5;
    }
    
    ans = ans + fives * 5;
    
    //@ assert ans == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    return ans;
}

int main() {
    return 0;
}
