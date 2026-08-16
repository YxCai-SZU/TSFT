#include <stddef.h>

/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == (((k) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t k)
{
    size_t ans;
    //@ assert (2 <= (k) && (k) <= 100);
    ans = (k + 1) / 2;
    //@ assert ans == (((k) + 1) / 2);
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    size_t result;
    
    result = func(2);
    assert(result == 1);
    
    result = func(5);
    assert(result == 3);
    
    result = func(100);
    assert(result == 50);
    
    return 0;
}
#endif
