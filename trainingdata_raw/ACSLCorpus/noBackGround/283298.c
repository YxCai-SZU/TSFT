#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    assigns \nothing;
*/
int32_t func(uint32_t x) {
    int32_t ans = 0;
    uint32_t temp_x = x;
    uint32_t count_500 = 0;
    uint32_t count_5 = 0;
    
    //@ assert (1 <= (x) && (x) <= 100000);
    //@ assert temp_x == x;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant temp_x <= x;
        loop invariant count_500 <= x / 500;
        loop invariant count_500 >= 0;
        loop invariant temp_x == x - 500 * count_500;
        loop invariant ans == 0;
        loop assigns temp_x, count_500;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        count_500 += 1;
        //@ assert temp_x == x - 500 * count_500;
    }
    
    ans += count_500 * 1000;
    //@ assert ans == 1000 * count_500;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant temp_x <= x;
        loop invariant count_5 <= (x - 500 * count_500) / 5;
        loop invariant count_5 >= 0;
        loop invariant temp_x == x - 500 * count_500 - 5 * count_5;
        loop invariant ans == 1000 * count_500;
        loop assigns temp_x, count_5, ans;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        count_5 += 1;
        //@ assert temp_x == x - 500 * count_500 - 5 * count_5;
    }
    
    ans += count_5 * 5;
    //@ assert ans == 1000 * count_500 + 5 * count_5;
    //@ assert ans == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    
    return ans;
}

int main() {
    return 0;
}
