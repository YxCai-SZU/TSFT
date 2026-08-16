#include <stdint.h>

/*@
    requires (0 <= (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at top of scope
    int32_t res;
    
    //@ assert 0 <= x <= 100;
    //@ assert ((x) * (x)) <= 10000;
    
    res = x * x;
    
    //@ assert res == ((x) * (x));
    return res;
}

int main(void)
{
    // Main function implementation
    return 0;
}
