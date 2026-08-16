#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x && x <= 1000000000;
    
    logic integer final_result(integer x) = 
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires valid_x(x);
    ensures \result == final_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t ans;
    uint64_t temp_x;
    uint64_t div_500;
    uint64_t rem_500;
    uint64_t div_5;
    uint64_t temp_rem_500;
    
    ans = 0;
    temp_x = x;
    div_500 = 0;
    
    //@ assert valid_x(x);
    
    /*@
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant div_500 <= x / 500;
        loop invariant temp_x == x - div_500 * 500;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        temp_x -= 500;
        div_500 += 1;
    }
    
    rem_500 = temp_x;
    
    div_5 = 0;
    temp_rem_500 = rem_500;
    
    /*@
        loop invariant 0 <= temp_rem_500 && temp_rem_500 <= rem_500;
        loop invariant div_5 <= rem_500 / 5;
        loop invariant temp_rem_500 == rem_500 - div_5 * 5;
        loop assigns temp_rem_500, div_5;
        loop variant temp_rem_500;
    */
    while (temp_rem_500 >= 5) {
        temp_rem_500 -= 5;
        div_5 += 1;
    }
    
    ans = div_500 * 1000 + div_5 * 5;
    
    return ans;
}

int main() {
    return 0;
}
