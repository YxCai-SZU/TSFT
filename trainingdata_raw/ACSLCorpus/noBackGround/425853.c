#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures ((\result) >= 0 && (\result) <= (n) + (m));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t result;
    uint64_t remaining;

    if (n < m) {
        result = n + m - 1;
        //@ assert result >= 0;
        //@ assert result <= n + m;
        return result;
    } else {
        remaining = n - m;
        //@ assert remaining / 4 <= n;
        result = m + remaining / 4;
        //@ assert result >= 0;
        //@ assert result <= n + m;
        return result;
    }
}
