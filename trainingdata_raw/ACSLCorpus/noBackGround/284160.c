#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_2;
    int64_t a_3;
    int64_t a_4;
    
    //@ assert 1 <= a <= 10;
    
    //@ assert ((a) * (a)) <= 100;
    a_2 = a * a;
    
    //@ assert ((a) * (a) * (a)) >= 1;
    //@ assert ((a) * (a) * (a)) <= 1000;
    a_3 = a * a * a;
    
    a_4 = a + a_2 + a_3;
    
    //@ assert a_4 == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return a_4;
}
