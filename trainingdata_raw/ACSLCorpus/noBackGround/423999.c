#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Declare all variables at the top
    int64_t a_2;
    int64_t a_3;
    int64_t a_total;
    
    //@ assert (1 <= (a) <= 100);
    
    // Verify a * a bounds
    //@ assert ((a) * (a)) >= 1 && ((a) * (a)) <= 10000;
    a_2 = a * a;
    
    // Verify a * a * a bounds  
    //@ assert ((a) * (a) * (a)) >= 1 && ((a) * (a) * (a)) <= 1000000;
    a_3 = a * a * a;
    
    // Verify final expression bounds
    //@ assert a + a_2 + a_3 >= 3 && a + a_2 + a_3 <= 1111000;
    a_total = a + a_2 + a_3;
    
    //@ assert a_total == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return a_total;
}
