#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    assigns \nothing;
    ensures \result == (((n) + 1) / 2);
*/
uint64_t func(uint64_t n)
{
    uint64_t result;
    //@ assert 1 <= n <= 100;
    result = (n + 1) / 2;
    //@ assert result == (((n) + 1) / 2);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    uint64_t test_result;
    
    test_result = func(1);
    assert(test_result == 1);
    
    test_result = func(2);
    assert(test_result == 1);
    
    test_result = func(3);
    assert(test_result == 2);
    
    test_result = func(4);
    assert(test_result == 2);
    
    test_result = func(100);
    assert(test_result == 50);
    
    return 0;
}
#endif
