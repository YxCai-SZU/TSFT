#include <stdint.h>

/*@
    requires x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t y;
    
    y = 1 - x;
    
    //@ assert (x == 0 ==> y == 1) && (x == 1 ==> y == 0);
    
    return (int32_t)y;
}

int main()
{
    return 0;
}
