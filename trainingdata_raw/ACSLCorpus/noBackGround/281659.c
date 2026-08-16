#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
size_t func(size_t a)
{
    // Variable declarations at top of scope
    size_t result;
    
    //@ assert 1 <= a <= 10;
    
    //@ assert a * a >= 1 && a * a <= 100;
    
    //@ assert 1 + a + a * a >= 2 && 1 + a + a * a <= 111;
    
    //@ assert a * (1 + a + a * a) >= 2 && a * (1 + a + a * a) <= 1110;
    
    //@ assert a * (1 + a + a * a) == a * (1 + a + a * a);
    
    result = a * (1 + a + a * a);
    
    //@ assert result == ((a) * (1 + (a) + (a) * (a)));
    
    return result;
}
