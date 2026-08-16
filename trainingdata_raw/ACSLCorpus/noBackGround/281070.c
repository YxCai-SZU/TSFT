#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires k <= 24 * 60;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k) {
    uint32_t start;
    uint32_t end;
    int32_t d;

    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    //@ assert start == ((h1) * 60 + (m1));
    //@ assert end == ((h2) * 60 + (m2));
    //@ assert start <= end;
    d = (int32_t)end - (int32_t)start - (int32_t)k;
    //@ assert d == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    return d;
}
