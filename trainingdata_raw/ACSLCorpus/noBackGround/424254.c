#include <stdint.h>

/*@
    requires ((a) > 0 && (a) < 0x100);
    ensures \result == ((a) + ((a) * (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert a > 0 && a < 0x100;
    
    //@ assert a * a < 0x10000;
    
    result = a + (a * a);
    
    //@ assert result == ((a) + ((a) * (a)));
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    uint32_t a = 0x5;
    uint32_t result;
    
    result = func(a);
    
    //@ assert result == a + (a * a);
    assert(result == a + (a * a));
    
    return 0;
}
#endif
