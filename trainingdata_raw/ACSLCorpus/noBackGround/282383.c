#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    ensures \result == ((a) + (b) + (c) - 1);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert a + b + c <= 30;
    
    result = a + b + c;
    result = result - 1;
    
    //@ assert result == ((a) + (b) + (c) - 1);
    return result;
}

#ifdef TEST
#include <assert.h>

void test_func(void)
{
    int32_t a = 1;
    int32_t b = 2;
    int32_t c = 3;
    int32_t result;
    
    result = func(a, b, c);
    //@ assert result == ((a) + (b) + (c) - 1);
    assert(result == (a + b + c - 1));
}
#endif
