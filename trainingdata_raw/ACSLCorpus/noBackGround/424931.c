#include <stdint.h>

/*@
  requires \valid(v + (0..2));
  requires v[0] >= 1 && v[0] <= 100;
  requires v[1] >= 1 && v[1] <= 100;
  requires v[2] >= 1 && v[2] <= 100;
  assigns \nothing;
  ensures \result >= 1;
  ensures \result <= ((v[0]) + (v[1]) + (v[2]));
*/
uint32_t func(uint32_t* v) {
    // Variable declarations at the top of scope
    uint32_t v0;
    uint32_t v1;
    uint32_t v2;
    uint32_t temp;
    uint32_t result;

    v0 = v[0];
    v1 = v[1];
    v2 = v[2];

    // First comparison and swap
    if (v1 < v0) {
        temp = v0;
        v0 = v1;
        v1 = temp;
    }
    //@ assert v0 <= v1;

    // Second comparison and swap
    if (v2 < v0) {
        temp = v0;
        v0 = v2;
        v2 = temp;
    }
    //@ assert v0 <= v2;

    // Third comparison and swap
    if (v2 < v1) {
        temp = v1;
        v1 = v2;
        v2 = temp;
    }
    //@ assert v1 <= v2;

    // Final sorted state
    //@ assert ((v0) <= (v1) && (v1) <= (v2));

    // Calculate result
    if (v0 < v1 + v2) {
        result = v0 + v1 + v2;
        //@ assert result == ((v0) + (v1) + (v2));
    } else {
        result = v1 + v2 + 1;
        //@ assert result == ((v1) + (v2) + (1));
    }

    return result;
}
