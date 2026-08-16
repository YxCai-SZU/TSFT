#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a));
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert a * a <= 100;
    //@ assert a + a * a <= 110;
    
    result = (int32_t)a + (int32_t)a * (int32_t)a;
    
    return result;
}

int main()
{
    return 0;
}
