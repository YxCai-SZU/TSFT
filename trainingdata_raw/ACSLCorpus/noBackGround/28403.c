#include <stdint.h>

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  requires 1 <= c <= 10000;
  requires 1 <= d <= 10000;
  ensures \result <= a || \result <= b || \result <= c || \result <= d;
  ensures \result >= a || \result >= b || \result >= c || \result >= d;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t min_val;
    uint32_t max_ab;
    uint32_t max_cd;
    uint32_t max_val;
    uint32_t result;

    // Calculate min_ab
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    // Calculate min_cd
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    // Calculate min_val
    if (min_ab < min_cd) {
        min_val = min_ab;
    } else {
        min_val = min_cd;
    }

    // Calculate max_ab
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }

    // Calculate max_cd
    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }

    // Calculate max_val
    if (max_ab > max_cd) {
        max_val = max_ab;
    } else {
        max_val = max_cd;
    }

    //@ assert ((min_val) <= (a) || (min_val) <= (b) || (min_val) <= (c) || (min_val) <= (d));
    //@ assert ((max_val) >= (a) || (max_val) >= (b) || (max_val) >= (c) || (max_val) >= (d));

    if (max_val <= 2 * min_val) {
        result = max_val;
    } else {
        result = 2 * min_val;
    }

    return result;
}
