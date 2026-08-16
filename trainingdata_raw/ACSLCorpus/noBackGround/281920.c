#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_pow_2;
    int64_t a_pow_3;
    int64_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_pow_3 = a * a * a;
    
    result = a + a_pow_2 + a_pow_3;
    
    //@ assert result == a + a * a + a * a * a;
    return result;
}

int main()
{
    return 0;
}
