#include <stddef.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 10000;
    
    logic integer compute_result(integer n) = (n / 1000) * 1000;
*/

/*@
    requires valid_range(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    
    //@ assert valid_range(n);
    result = n / 1000;
    
    //@ assert result == n / 1000;
    return result * 1000;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    size_t test_result;
    
    test_result = func(1234);
    //@ assert test_result == 1000;
    assert(test_result == 1000);
    
    return 0;
}
#endif
