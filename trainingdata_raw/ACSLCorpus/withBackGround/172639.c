#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer sum_four(integer a, integer b, integer c, integer d) = a + b + c + d;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == sum_four(a, b, c, d);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    result = a + b + c + d;
    //@ assert result == sum_four(a, b, c, d);
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    uint32_t test_result;
    test_result = func(1, 2, 3, 4);
    //@ assert test_result == 10;
    assert(test_result == 10);
    return 0;
}
#endif
