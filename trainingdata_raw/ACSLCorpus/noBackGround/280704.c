#include <stdint.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) + (((x)) * ((x))) + (((x)) * ((x)) * ((x))));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert x >= 1 && x <= 10;
    
    //@ assert x * x >= 1 && x * x <= 100;
    
    //@ assert x * x * x >= 1 && x * x * x <= 1000;
    
    result = x + (x * x) + (x * x * x);
    
    //@ assert result == ((x) + (((x)) * ((x))) + (((x)) * ((x)) * ((x))));
    
    return result;
}

#ifdef TEST
#include <assert.h>

void test_func(void)
{
    int32_t x = 2;
    int32_t result = func(x);
    //@ assert result == 2 + (2 * 2) + (2 * 2 * 2);
    assert(result == 14);
}
#endif
