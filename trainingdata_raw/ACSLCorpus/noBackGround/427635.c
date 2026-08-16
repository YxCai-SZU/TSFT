#include <stdint.h>
/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) * (x)) || 
            \result == ((k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t x, uint32_t y) {
    uint32_t res;
    
    if (n <= k) {
        //@ assert 1 <= n && n <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert n * x <= 10000 * 10000;
        res = n * x;
    } else {
        //@ assert 1 <= k && k <= 10000;
        //@ assert 1 <= x && x <= 10000;
        //@ assert 1 <= y && y < x && x <= 10000;
        //@ assert k * x <= 10000 * 10000;
        //@ assert (n - k) * y <= 10000 * 10000;
        res = k * x + (n - k) * y;
    }
    
    return res;
}

int main() {
    return 0;
}
