#include <stdint.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    return (n - 1) * (m - 1);
}
