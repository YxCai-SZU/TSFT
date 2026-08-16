#include <stdint.h>

/*@
    requires (2 <= (n) <= 100);
    requires (2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Declare all variables at the top
    int32_t result;

    //@ assert n >= 2 && n <= 100;
    //@ assert m >= 2 && m <= 100;
    
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;

    //@ assert (n - 1) * (m - 1) >= 1;
    //@ assert (n - 1) * (m - 1) <= 9801;

    result = (n - 1) * (m - 1);
    
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
