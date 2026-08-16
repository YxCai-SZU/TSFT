#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert 0 <= ((a) * (a)) <= 100;
    //@ assert 0 <= ((a) * (a) * (a)) <= 1000;

    result = a;
    
    //@ assert result == a;
    //@ assert 0 <= ((a) * (a)) <= 100;
    result += a * a;
    
    //@ assert result == a + ((a) * (a));
    //@ assert 0 <= ((a) * (a) * (a)) <= 1000;
    result += a * a * a;
    
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}
