#include <stdint.h>

/*@
    requires (1 <= (x) <= 179);
    ensures \result == (360 - (x));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (x) <= 179);
    //@ assert 360 - x >= 0;
    
    result = 360 - x;
    
    //@ assert result == (360 - (x));
    return result;
}

int main(void)
{
    return 0;
}
