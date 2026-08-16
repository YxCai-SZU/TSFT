#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert n == m || n != m;
    
    result = (n == m);
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    bool test_result;
    
    test_result = func(5, 5);
    assert(test_result == true);
    
    test_result = func(5, 3);
    assert(test_result == false);
    
    return 0;
}
#endif
