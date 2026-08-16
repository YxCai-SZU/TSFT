#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert (3 <= (n) && (n) <= 100);
    
    result = (n - 2) * 180;
    
    //@ assert result == (((n) - 2) * 180);
    
    return result;
}

int main(void)
{
    return 0;
}
