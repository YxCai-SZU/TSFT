#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures \result == ((x) * ((x) * (x)));
    assigns \nothing;
 */
int64_t func(int64_t x)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 0 <= x && x <= 1000000000;
    
    result = x * (x * x);
    
    //@ assert result == ((x) * ((x) * (x)));
    return result;
}

int main()
{
    return 0;
}
