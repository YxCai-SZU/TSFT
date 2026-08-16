#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 && 2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Declare all variables at the top
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    uint32_t temp_result;
    int32_t result;

    // Precondition verification
    //@ assert (2 <= (n) && (n) <= 100 && 2 <= (m) && (m) <= 100);

    // Underflow prevention
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;

    // Overflow prevention
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    n_unsigned = (uint32_t)n;
    m_unsigned = (uint32_t)m;

    // Safe subtraction
    //@ assert n_unsigned >= 1;
    //@ assert m_unsigned >= 1;

    temp_result = (n_unsigned - 1) * (m_unsigned - 1);
    result = (int32_t)temp_result;

    // Postcondition verification
    //@ assert result == (((n) - 1) * ((m) - 1));

    return result;
}
