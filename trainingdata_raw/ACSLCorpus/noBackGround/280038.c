#include <stdint.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 23 * 60 + 59;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k) {
    int64_t s;
    int64_t t;
    int64_t ans;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    s = h1 * 60 + m1;
    //@ assert s == ((h1) * 60 + (m1));
    
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    t = h2 * 60 + m2;
    //@ assert t == ((h2) * 60 + (m2));
    
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ans = t - s - k;
    //@ assert ans == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    
    return ans;
}
