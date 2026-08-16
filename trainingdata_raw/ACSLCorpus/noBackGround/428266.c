#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures ((\result) == 0 || (\result) == 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans = 0;
    uint32_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant ((ans) == 0 || (ans) == 1);
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
        loop assigns ans, i;
        loop variant n - i + 1;
    */
    while (i <= n) {
        uint32_t div = 1;
        bool is_divisible = false;
        
        /*@
            loop invariant 1 <= div <= m;
            loop invariant ((ans) == 0 || (ans) == 1);
            loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
            loop invariant 1 <= i <= n + 1;
            loop assigns div, is_divisible;
            loop variant m - div;
        */
        while (div < m) {
            //@ assert div > 0;
            if (i % div == 0) {
                is_divisible = true;
                break;
            }
            div += 1;
        }
        
        if (is_divisible) {
            ans = 1;
            break;
        }
        i += 1;
    }
    return ans;
}
