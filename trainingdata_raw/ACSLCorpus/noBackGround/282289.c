#include <stdbool.h>
#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 24) && (0 <= (b) && (b) < 24);
    ensures \result == ((((a) + (b)) % 24));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    sum = a + b;
    result = sum % 24;
    //@ assert result == ((((a) + (b)) % 24));
    return result;
}

/*@
    requires is_some != 0 ==> (opt_value >= 0);
    ensures \result == ((is_some) != 0 ? (opt_value) : (default_val));
    assigns \nothing;
*/
uint32_t unwrap_or_default(uint32_t opt_value, bool is_some, uint32_t default_val)
{
    uint32_t result;
    if (is_some) {
        result = opt_value;
    } else {
        result = default_val;
    }
    //@ assert result == ((is_some) != 0 ? (opt_value) : (default_val));
    return result;
}
