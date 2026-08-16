#include <stdint.h>

/*@
    predicate sorted(uint32_t a, uint32_t b, uint32_t c) =
        a <= b && b <= c;

    lemma sort_network_lemma:
        \forall uint32_t a, b, c;
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 ==>
        sorted(a, b, c) || sorted(a, c, b) || sorted(b, a, c) || 
        sorted(b, c, a) || sorted(c, a, b) || sorted(c, b, a);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t min;
    uint32_t mid;
    uint32_t max;
    uint32_t temp;

    min = a;
    mid = b;
    max = c;

    //@ assert min == a && mid == b && max == c;

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

    //@ assert sorted(min, mid, max);

    if (max - min == 0) {
        //@ assert max - min == 0;
        return 1;
    } else if (max - min == 1) {
        //@ assert max - min == 1;
        return 2;
    } else {
        //@ assert max - min > 1;
        return 3;
    }
}
