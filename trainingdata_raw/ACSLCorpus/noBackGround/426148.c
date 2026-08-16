#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((314 * (r) * 2) / 100);
    assigns \nothing;
*/
int32_t func(uint32_t r) {
    int32_t pi_approx;
    int32_t scale;
    int32_t ans;
    int32_t temp;
    
    pi_approx = 314;
    scale = 100;
    ans = 0;
    temp = (int32_t)r * 2 * pi_approx;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant scale == 100;
        loop invariant ans >= 0;
        loop invariant temp >= 0;
        loop invariant temp == (int32_t)r * 2 * pi_approx - ans * scale;
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= scale) {
        //@ assert temp >= scale;
        ans += 1;
        temp -= scale;
    }
    
    //@ assert ans == ((314 * (r) * 2) / 100);
    return ans;
}

int main(void) {
    return 0;
}
