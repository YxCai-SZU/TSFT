#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
int32_t func(uint32_t x) {
    int32_t ans = 0;
    uint32_t temp_x = x;
    uint32_t quotient_500 = 0;
    uint32_t remainder_500 = temp_x;
    
    /*@
        loop invariant 1 <= x && x <= 100000;
        loop invariant 0 <= quotient_500;
        loop invariant remainder_500 >= 0;
        loop invariant remainder_500 == temp_x - quotient_500 * 500;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500) {
        quotient_500 += 1;
        remainder_500 -= 500;
    }
    
    ans += quotient_500 * 1000;
    temp_x = remainder_500;
    
    uint32_t quotient_5 = 0;
    uint32_t remainder_5 = temp_x;
    
    /*@
        loop invariant 1 <= x && x <= 100000;
        loop invariant 0 <= quotient_5;
        loop invariant remainder_5 >= 0;
        loop invariant remainder_5 == temp_x - quotient_5 * 5;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5) {
        quotient_5 += 1;
        remainder_5 -= 5;
    }
    
    ans += quotient_5 * 5;
    
    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return ans;
}

int main() {
    return 0;
}
