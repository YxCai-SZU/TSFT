#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 - x == 1 - x;
    
    result = 1 - x;
    return result;
}

int main()
{
    // Variable declarations at top of scope
    int64_t x;
    
    return 0;
}
