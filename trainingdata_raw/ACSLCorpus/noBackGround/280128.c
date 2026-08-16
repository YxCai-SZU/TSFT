#include <stdint.h>

/*@
    requires (0 <= (x) <= 0xFFFF) && (0 <= (y) <= 0xFFFF) && (0 <= (z) <= 0xFFFF);
    ensures \result == ((x) * (y) + (z));
    assigns \nothing;
*/
uint32_t non_linear_arith_example3(uint32_t x, uint32_t y, uint32_t z)
{
    //@ assert (0 <= (x) <= 0xFFFF);
    //@ assert (0 <= (y) <= 0xFFFF);
    //@ assert (0 <= (z) <= 0xFFFF);
    
    //@ assert x * y <= 0xFFFF * 0xFFFF;
    //@ assert x * y + z <= 0xFFFF * 0xFFFF + 0xFFFF;
    
    return x * y + z;
}

int main()
{
    return 0;
}
