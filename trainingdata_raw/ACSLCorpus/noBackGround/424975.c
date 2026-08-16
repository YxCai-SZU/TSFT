#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (((a)) * ((a)))));
    assigns \nothing;
*/
size_t func(size_t a)
{
    // Variable declarations at top of scope
    size_t a_pow_2;
    size_t a_pow_3;
    size_t a_plus_1;
    size_t a_times_2;
    size_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_pow_3 = a * a * a;
    
    a_plus_1 = a + 1;
    a_times_2 = a * 2;
    
    //@ assert 1 <= a_times_2 && a_times_2 <= 20;
    
    //@ assert 1 <= 1 + a + a_pow_2 && 1 + a + a_pow_2 <= 111;
    
    //@ assert 1 <= a * (1 + a + a_pow_2) && a * (1 + a + a_pow_2) <= 1110;
    
    result = a * (1 + a + a_pow_2);
    return result;
}
