#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b, integer c, integer d) =
        1 <= a <= 10000 &&
        1 <= b <= 10000 &&
        1 <= c <= 10000 &&
        1 <= d <= 10000 &&
        a <= b &&
        c <= d;

    logic integer max_val(integer a, integer c) = (a > c) ? a : c;
    logic integer min_val(integer b, integer d) = (b < d) ? b : d;

    lemma ans_bounds:
        \forall integer a, b, c, d;
        valid_range(a, b, c, d) ==>
        (
            \let max_start = max_val(a, c);
            \let min_end = min_val(b, d);
            \let ans = (min_end >= max_start) ? (min_end - max_start) : 0;
            ans >= 0 && ans <= b - a && ans <= d - c
        );
*/

/*@
    requires valid_range(a, b, c, d);
    ensures \result >= 0 && \result <= b - a && \result <= d - c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max_start;
    int64_t min_end;
    int64_t ans;

    //@ assert valid_range(a, b, c, d);
    
    if (a > c) {
        max_start = a;
    } else {
        max_start = c;
    }
    //@ assert max_start >= 0;
    
    if (b < d) {
        min_end = b;
    } else {
        min_end = d;
    }
    //@ assert min_end >= 0;
    
    if (min_end >= max_start) {
        ans = min_end - max_start;
    } else {
        ans = 0;
    }
    //@ assert ans >= 0;
    
    return ans;
}
