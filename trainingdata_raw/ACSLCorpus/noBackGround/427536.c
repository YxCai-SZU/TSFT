#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t intermediate;
    int32_t result;

    //@ assert (1 <= (a) <= 10);
    
    //@ assert 1 <= a * a && a * a <= 100;
    intermediate = a + a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    result = intermediate + a * a * a;
    
    //@ assert result == a + a * a + a * a * a;
    return result;
}
