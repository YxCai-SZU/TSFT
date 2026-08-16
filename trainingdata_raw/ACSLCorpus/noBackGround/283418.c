#include <stdint.h>

/*@
    requires
        (0 <= (h1) <= 23 && 0 <= (m1) <= 59) && (0 <= (h2) <= 23 && 0 <= (m2) <= 59) &&
        ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2))) &&
        0 <= k <= 24 * 60 - 1;
    ensures
        \result == (int64_t)(((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k);
*/
int64_t func(uint64_t h1, uint64_t m1, uint64_t h2, uint64_t m2, uint64_t k)
{
    uint64_t start;
    uint64_t end;
    int64_t ans;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    
    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    
    //@ assert end >= start;
    //@ assert end - start <= 24 * 60;
    
    ans = (int64_t)end - (int64_t)start - (int64_t)k;
    return ans;
}
