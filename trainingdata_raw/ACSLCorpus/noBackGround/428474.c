#include <stdint.h>

/*@
    requires 0 <= x <= 10;
    ensures \result == ((x) * (x) * (x) - 3 * (x) * (x) + 2 * (x) - 1);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 0 <= x <= 10;
    //@ assert x * x <= 100;
    //@ assert x * x * x <= 1000;
    //@ assert 3 * x * x <= 300;
    //@ assert 2 * x <= 20;
    
    result = x * x * x - 3 * x * x + 2 * x - 1;
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    assert(func(2) == 3);
    assert(func(5) == 175);
    return 0;
}
#endif
