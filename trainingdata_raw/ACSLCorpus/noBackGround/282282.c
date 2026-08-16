#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;

    result = (n == m);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test cases
    bool test1 = func(10, 5);
    bool test2 = func(10, 10);
    bool test3 = func(100, 0);
    
    assert(test1 == false);
    assert(test2 == true);
    assert(test3 == false);
    
    return 0;
}
#endif
