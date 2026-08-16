#include <stdint.h>

/*@
    requires (3 <= (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert (3 <= (n) <= 100);
    
    result = ((int32_t)n - 2) * 180;
    
    //@ assert result == (((n) - 2) * 180);
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    assert(func(3) == 180);
    assert(func(4) == 360);
    assert(func(5) == 540);
    assert(func(6) == 720);
    assert(func(100) == 17640);
    return 0;
}
#endif
