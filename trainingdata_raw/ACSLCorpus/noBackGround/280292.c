#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    requires k <= 48 * 60;
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k) {
    uint32_t t1;
    uint32_t t2;
    int32_t result;

    t1 = h1 * 60 + m1;
    //@ assert t1 == ((h1) * 60 + (m1));
    
    t2 = h2 * 60 + m2;
    //@ assert t2 == ((h2) * 60 + (m2));
    
    result = (int32_t)t2 - (int32_t)t1 - (int32_t)k;
    return result;
}
