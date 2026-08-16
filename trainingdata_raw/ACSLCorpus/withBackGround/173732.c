#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n && n <= 10000;

    logic integer div_100(integer n) = n / 100;
    logic integer div_1000(integer n) = n / 1000;
    logic integer expected_result(integer n) = div_100(n) + div_1000(n);

    lemma div_properties:
        \forall integer n; valid_range(n) ==> 
            div_100(n) == n / 100 && div_1000(n) == n / 1000;
*/

/*@
    requires valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    uint32_t result;

    //@ assert valid_range(n);
    x = n / 100;
    y = n / 1000;
    //@ assert x == div_100(n);
    //@ assert y == div_1000(n);
    result = x + y;
    //@ assert result == expected_result(n);
    return result;
}

/*@
    requires valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint32_t func2(uint32_t n)
{
    uint32_t result;

    //@ assert valid_range(n);
    //@ assert n / 100 == div_100(n);
    //@ assert n / 1000 == div_1000(n);
    result = n / 100 + n / 1000;
    //@ assert result == expected_result(n);
    return result;
}
