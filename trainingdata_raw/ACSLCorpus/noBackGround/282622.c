#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert ((a) + ((a) * (a)) + ((a) * (a) * (a))) <= 10 + (10 * 10) + (10 * 10 * 10);

    result = a + (a * a) + (a * a * a);
    
    //@ assert result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    return result;
}
