#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * (a));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Declare all variables at scope beginning
    int32_t a_2;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert ((a) * (a)) <= 10000;
    
    a_2 = a * a;
    
    //@ assert a_2 == ((a) * (a));
    
    return a_2;
}
