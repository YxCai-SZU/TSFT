#include <stdint.h>

/*@
    requires (0 <= (x) <= 4);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t cubed(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert x <= 4;
    //@ assert x * x <= 16;
    //@ assert x * x * x <= 64;
    
    result = x * x * x;
    return result;
}

/*@
    assigns \nothing;
*/
void use_cubed(void)
{
    // Variable declarations at top of scope
    uint32_t r;
    
    r = cubed(3);
    //@ assert r == 27;
}

int main(void)
{
    use_cubed();
    return 0;
}
