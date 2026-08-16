#include <stdint.h>

/*@
    predicate sorted(integer a, integer b, integer c) =
        a <= b && b <= c;

    lemma diff_bounds:
        \forall integer a, b, c;
            1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && sorted(a, b, c) ==>
            c - a >= 0 && c - a <= 99;

    lemma ans_range:
        \forall integer diff;
            diff >= 0 && diff <= 99 ==>
            (diff == 0 ==> 1 >= 1 && 1 <= 3) &&
            (diff == 1 ==> 2 >= 1 && 2 <= 3) &&
            (diff != 0 && diff != 1 ==> 3 >= 1 && 3 <= 3);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min_val;
    int64_t mid_val;
    int64_t max_val;
    int64_t temp;
    int64_t diff;
    int64_t ans;

    min_val = a;
    mid_val = b;
    max_val = c;

    //@ assert 1 <= min_val <= 100 && 1 <= mid_val <= 100 && 1 <= max_val <= 100;

    if (min_val > mid_val)
    {
        temp = min_val;
        min_val = mid_val;
        mid_val = temp;
    }

    //@ assert min_val <= mid_val;

    if (mid_val > max_val)
    {
        temp = mid_val;
        mid_val = max_val;
        max_val = temp;
    }

    //@ assert mid_val <= max_val;

    if (min_val > mid_val)
    {
        temp = min_val;
        min_val = mid_val;
        mid_val = temp;
    }

    //@ assert sorted(min_val, mid_val, max_val);
    //@ assert max_val >= min_val;
    //@ assert max_val - min_val <= 99;

    diff = max_val - min_val;

    if (diff == 0)
    {
        ans = 1;
    }
    else if (diff == 1)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
