#include <stdint.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t min;
    uint32_t mid;
    uint32_t max;
    uint32_t temp;
    uint32_t ans;

    min = a;
    mid = b;
    max = c;

    if (min > mid) {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert min <= mid;

    if (mid > max) {
        temp = mid;
        mid = max;
        max = temp;
    }
    //@ assert mid <= max;

    if (min > mid) {
        temp = min;
        min = mid;
        mid = temp;
    }
    //@ assert min <= mid && mid <= max;

    ans = 1;

    if (min == mid && mid == max) {
        ans = 1;
        //@ assert ans == 1;
    } else if (min == mid || mid == max) {
        ans = 2;
        //@ assert ans == 2;
    } else {
        ans = 3;
        //@ assert ans == 3;
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
