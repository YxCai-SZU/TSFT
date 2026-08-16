#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == n - k + 1;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t result;
    //@ assert n - k + 1 == n - k + 1;
    result = n - k + 1;
    return result;
}
