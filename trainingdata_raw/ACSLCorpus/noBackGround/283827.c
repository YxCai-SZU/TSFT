#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 500);
    ensures \result == (6 * (n) + ((n) - 1));
    ensures \result >= n;
    assigns \nothing;
*/
uint32_t find_star_num(uint32_t n) {
    //@ assert (1 <= (n) && (n) <= 500);
    //@ assert 6 * n <= 3000;
    //@ assert 6 * n + (n - 1) <= 3499;
    //@ assert 6 * n + (n - 1) >= 6;
    
    return 6 * n + (n - 1);
}
