#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_input(integer h, integer a) =
        1 <= h && h <= 10000 &&
        1 <= a && a <= 10000;

    logic integer ceil_div(integer h, integer a) =
        h % a == 0 ? h / a : h / a + 1;

    lemma ceil_div_bounds:
        \forall integer h, a;
        valid_input(h, a) ==>
        ceil_div(h, a) >= h / a &&
        ceil_div(h, a) <= h / a + 1;
*/

/*@
    requires valid_input(h, a);
    ensures \result == ceil_div(h, a);
    ensures \result >= h / a;
    ensures \result <= h / a + 1;
*/
uint32_t func(uint32_t h, uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t ans;

    ans = h / a;
    //@ assert ans == h / a;

    if (h % a != 0)
    {
        ans = ans + 1;
        //@ assert ans == h / a + 1;
    }

    //@ assert ans == ceil_div(h, a);
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test cases
    assert(func(10, 3) == 4);
    assert(func(10, 5) == 2);
    assert(func(100, 21) == 5);
    return 0;
}
#endif
