#include <stdint.h>

/*@
    logic integer func_spec(integer n) =
        (n / 500) * 1000 + (n % 500) / 5 * 5;
*/

/*@
    requires 1 <= n <= 100000;
    assigns \nothing;
    ensures \result == func_spec(n);
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    //@ assert 1 <= n <= 100000;
    result = n / 500 * 1000 + n % 500 / 5 * 5;
    //@ assert result == func_spec(n);
    return result;
}

/*@
    lemma func_postconditions:
        \forall integer n, integer result;
            1 <= n <= 100000 && result == func_spec(n) ==>
            result == func_spec(n);
*/
