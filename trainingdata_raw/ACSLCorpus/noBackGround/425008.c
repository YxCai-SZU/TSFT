#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 2 * r * 314159 / 100000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_scaled;
    int64_t scale_factor;
    int64_t product;
    int64_t ans;
    int64_t remainder;
    
    pi_scaled = 314159;
    scale_factor = 100000;
    product = 2 * r * pi_scaled;
    ans = 0;
    remainder = product;
    
    //@ assert ((1 <= ((r)) && ((r)) <= 100) &&         (pi_scaled) == 314159 &&         (scale_factor) == 100000 &&         (product) == 2 * (r) * (pi_scaled) &&         (ans) >= 0 &&         (remainder) >= 0 &&         (remainder) == (product) - (ans) * (scale_factor));
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (pi_scaled) == 314159 &&
        (scale_factor) == 100000 &&
        (product) == 2 * (r) * (pi_scaled) &&
        (ans) >= 0 &&
        (remainder) >= 0 &&
        (remainder) == (product) - (ans) * (scale_factor));
        loop assigns ans, remainder;
        loop variant remainder;
    */
    while (remainder >= scale_factor) {
        ans += 1;
        remainder -= scale_factor;
        //@ assert ((1 <= ((r)) && ((r)) <= 100) &&         (pi_scaled) == 314159 &&         (scale_factor) == 100000 &&         (product) == 2 * (r) * (pi_scaled) &&         (ans) >= 0 &&         (remainder) >= 0 &&         (remainder) == (product) - (ans) * (scale_factor));
    }
    
    //@ assert remainder == product - ans * scale_factor;
    //@ assert ans * scale_factor + remainder == product;
    
    return ans;
}

int main() {
    return 0;
}
