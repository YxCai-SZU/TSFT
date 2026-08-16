#include <stdint.h>

/*@
    predicate valid_input(integer n) = 2 <= n && n <= 100;
    
    logic integer expected_result(integer n) = (n - 1) / 2 + 1;
*/

/*@
    requires valid_input(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t ans;
    
    //@ assert valid_input(n);
    ans = (n - 1) / 2 + 1;
    
    //@ assert ans == expected_result(n);
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    uint64_t n = 10;
    uint64_t ans = func(n);
    assert(ans == 5);
    return 0;
}
#endif
