#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    lemma min_sum:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            min(a, b) + min(c, d) == ((a < b) ? a : b) + ((c < d) ? c : d);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == ((a < b) ? a : b) + ((c < d) ? c : d);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans;
    int64_t tmp1;
    int64_t tmp2;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    tmp1 = (a < b) ? a : b;
    tmp2 = (c < d) ? c : d;
    ans = tmp1 + tmp2;

    //@ assert ans == ((a < b) ? a : b) + ((c < d) ? c : d);
    return ans;
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(2, 1, 3, 4) == 5);
    assert(func(10, 20, 30, 40) == 30);
    assert(func(10000, 2000, 3000, 4000) == 5000);
    assert(func(1, 1, 1, 1) == 2);
    assert(func(1, 10000, 1, 10000) == 2);
    return 0;
}
#endif
