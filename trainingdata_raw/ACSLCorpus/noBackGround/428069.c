#include <stdint.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    requires 0 <= k <= 100000;
    ensures \result == ((h2) * 60 + (m2) - (h1) * 60 - (m1)) - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    //@ assert ((h2) * 60 + (m2) - (h1) * 60 - (m1)) >= 0;
    //@ assert ((h2) * 60 + (m2) - (h1) * 60 - (m1)) <= 100000;
    
    int64_t result;
    result = (h2 * 60 + m2 - h1 * 60 - m1 - k);
    return result;
}
