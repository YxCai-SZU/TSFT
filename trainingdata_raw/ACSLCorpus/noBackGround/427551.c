#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result == ((3 * (a) + (p)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t p)
{
    uint64_t result;
    //@ assert (0 <= (a) <= 100 && 0 <= (p) <= 100);
    result = (3 * a + p) / 2;
    //@ assert result == ((3 * (a) + (p)) / 2);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    uint64_t a;
    uint64_t p;
    uint64_t result;
    
    a = 3;
    p = 2;
    result = func(a, p);
    assert(result == (3 * a + p) / 2);
    
    a = 0;
    p = 0;
    result = func(a, p);
    assert(result == (3 * a + p) / 2);
    
    a = 100;
    p = 100;
    result = func(a, p);
    assert(result == (3 * a + p) / 2);
    
    a = 25;
    p = 25;
    result = func(a, p);
    assert(result == (3 * a + p) / 2);
    
    return 0;
}
#endif
