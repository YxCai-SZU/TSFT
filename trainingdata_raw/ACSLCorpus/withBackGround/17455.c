#include <stdint.h>
/*@
    predicate valid_range(integer a, integer b, integer x) =
        0 <= a <= b <= 1000000000000000000 && 1 <= x <= 1000000000000000000;

    logic integer floor_div(integer n, integer d) = n / d;

    lemma division_monotonic:
        \forall integer a, b, x;
        valid_range(a, b, x) ==> floor_div(a, x) <= floor_div(b, x);
*/

/*@
    requires valid_range(a, b, x);
    ensures \result <= floor_div(b, x) - floor_div(a, x) + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x) {
    uint64_t cnt;
    //@ assert floor_div(a, x) <= floor_div(b, x);
    if (a / x == b / x) {
        cnt = b / x - a / x;
    } else {
        cnt = b / x - a / x + 1;
    }
    return cnt;
}

#ifdef TEST
#include <assert.h>
int main() {
    assert(func(13, 47, 5) == 3);
    assert(func(15, 20, 5) == 1);
    assert(func(0, 1, 5) == 1);
    assert(func(10, 15, 5) == 1);
    return 0;
}
#endif
