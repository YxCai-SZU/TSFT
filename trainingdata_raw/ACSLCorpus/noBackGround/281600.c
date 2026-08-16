#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result >= 0;
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
int64_t func(int64_t x) {
    int64_t ans = 0;
    int64_t temp_x = x;
    int64_t div_500 = 0;
    int64_t mod_500_div_5 = 0;
    
    //@ assert (1 <= (x) && (x) <= 100000);
    
    /*@
        loop invariant 1 <= x && x <= 100000;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 500 * div_500;
        loop invariant div_500 >= 0;
        loop invariant div_500 <= x / 500;
        loop assigns temp_x, div_500;
    */
    while (temp_x >= 500) {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        div_500 += 1;
        //@ assert temp_x == x - 500 * div_500;
    }
    
    /*@
        loop invariant 1 <= x && x <= 100000;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 500 * div_500 - 5 * mod_500_div_5;
        loop invariant mod_500_div_5 >= 0;
        loop invariant mod_500_div_5 <= (x - 500 * div_500) / 5;
        loop assigns temp_x, mod_500_div_5;
    */
    while (temp_x >= 5) {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        mod_500_div_5 += 1;
        //@ assert temp_x == x - 500 * div_500 - 5 * mod_500_div_5;
    }
    
    //@ assert div_500 <= x / 500;
    //@ assert mod_500_div_5 <= (x - 500 * div_500) / 5;
    //@ assert 500 * div_500 <= 500 * (x / 500);
    //@ assert 5 * mod_500_div_5 <= 5 * ((x - 500 * div_500) / 5);
    //@ assert 500 * div_500 + 5 * mod_500_div_5 <= x;
    //@ assert 1000 * div_500 + 5 * mod_500_div_5 <= 1000 * (x / 500) + 5 * ((x - 500 * div_500) / 5);
    
    ans += div_500 * 1000;
    ans += mod_500_div_5 * 5;
    
    //@ assert ans >= 0;
    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return ans;
}
