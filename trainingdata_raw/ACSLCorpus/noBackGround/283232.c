#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == ((a) == (b) && (b) == (c) ? 1 :
        (a) != (b) && (b) != (c) && (c) != (a) ? 3 :
        2);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;

    if (a == b && b == c) {
        ans = 1;
    } else if (a != b && b != c && c != a) {
        ans = 3;
    } else {
        ans = 2;
    }

    //@ assert ans >= 1;
    //@ assert ans <= 3;
    //@ assert ans == ((a) == (b) && (b) == (c) ? 1 :         (a) != (b) && (b) != (c) && (c) != (a) ? 3 :         2);

    return ans;
}
