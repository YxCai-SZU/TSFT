#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even_spec(integer x) = x % 2 == 0; */
/*@ predicate is_odd_spec(integer x) = x % 2 != 0; */

/*@
    requires 0 <= x <= 4294967295;
    ensures \result == true <==> x % 2 == 0;
    assigns \nothing;
*/
bool is_even(uint32_t x)
{
    bool result;
    //@ assert 0 <= x <= 4294967295;
    if (x % 2 == 0) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == true <==> x % 2 == 0;
    return result;
}

/*@
    requires 1 <= n <= 100;
    requires 0 <= a <= n * n;
    ensures \result == n * n - a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    uint32_t result;
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    result = n * n - a;
    //@ assert result == n * n - a;
    return result;
}
