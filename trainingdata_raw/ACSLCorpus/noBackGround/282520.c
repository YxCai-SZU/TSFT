#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= (n) && (n) <= 1000000000);
    assigns \nothing;
    ensures \result >= (((n) - 2) / ((k) - 1));
    ensures \result <= (((n) - 2) / ((k) - 1) + 1);
*/
uint64_t func(uint64_t n, uint64_t k) {
    uint64_t ans;
    
    if (n == 2) {
        //@ assert (((n) - 2) / ((k) - 1)) == 0;
        //@ assert (((n) - 2) / ((k) - 1) + 1) == 1;
        return 1;
    }

    ans = (n - 2) / (k - 1);

    if ((n - 2) % (k - 1) > 0) {
        //@ assert ans == (((n) - 2) / ((k) - 1));
        //@ assert ans < (((n) - 2) / ((k) - 1) + 1);
        return ans + 1;
    } else {
        //@ assert ans == (((n) - 2) / ((k) - 1));
        //@ assert ans >= (((n) - 2) / ((k) - 1));
        return ans;
    }
}
