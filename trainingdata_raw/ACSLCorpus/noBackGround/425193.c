#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10);
    ensures \result == x + x*x + x*x*x;
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at top of scope
    int32_t x2;
    int32_t x3;
    int32_t result;
    
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert x*x <= 100;
    //@ assert x*x*x <= 1000;
    
    x2 = x * x;
    x3 = x * x * x;
    result = x + x2 + x3;
    
    //@ assert result == x + x*x + x*x*x;
    return result;
}

int main()
{
    // Variable declarations at top of scope
    // No function calls needed
    return 0;
}
