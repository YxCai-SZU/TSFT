#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000 && 1 <= (m) <= 1000000000);
    ensures \result <= n + m;
    ensures \result >= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t min_n;
    uint64_t ans;
    uint64_t temp;

    //@ assert (1 <= (n) <= 1000000000 && 1 <= (m) <= 1000000000);
    
    if (n < m) {
        min_n = n;
    } else {
        min_n = m;
    }

    //@ assert min_n == ((n) < (m) ? (n) : (m));
    //@ assert min_n * 2 <= 2000000000;

    temp = min_n * 2 + 1;
    //@ assert temp == ((n) < (m) ? (n) : (m)) * 2 + 1;

    if (n + m < temp) {
        ans = n + m;
    } else {
        ans = temp;
    }

    //@ assert ans == (((((n)) < ((m)) ? ((n)) : ((m))) * 2 + 1) < ((n) + (m)) ? ((((n)) < ((m)) ? ((n)) : ((m))) * 2 + 1) : ((n) + (m)));
    //@ assert ans <= n + m;
    //@ assert ans >= 1;

    return ans;
}
