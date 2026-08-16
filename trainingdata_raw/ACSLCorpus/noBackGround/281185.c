#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t result;
    
    //@ assert 1 <= a && a <= 10;
    result = a + a * a + a * a * a;
    //@ assert result == a + a * a + a * a * a;
    return result;
}

int main(void)
{
    return 0;
}
