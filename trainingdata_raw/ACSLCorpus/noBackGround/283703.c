#include <stdint.h>

/*@
  requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
  requires (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
  requires 0 <= k && k <= 23 * 60 + 59;
  requires ((h1) * 60 + (m1) <= (h2) * 60 + (m2));
  ensures \result == h2 * 60 + m2 - (h1 * 60 + m1 + k);
  assigns \nothing;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k) {
    // Variable declarations at scope top
    int32_t t1;
    int32_t t2;
    int32_t diff;
    int32_t result;

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;
    diff = t2 - t1;

    // Critical verification property
    //@ assert diff == h2 * 60 + m2 - (h1 * 60 + m1);

    result = diff - k;

    // Postcondition
    //@ assert result == h2 * 60 + m2 - (h1 * 60 + m1 + k);
    return result;
}
