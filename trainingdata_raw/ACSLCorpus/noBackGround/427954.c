#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000) && (1 <= (t) && (t) <= 10000) && (1 <= (s) && (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert t * s <= 10000 * 10000;
    
    result = d <= t * s;
    return result;
}

/* Test function */
#ifdef TEST
#include <assert.h>
int main()
{
    bool test_result;
    
    test_result = func(100, 3, 50);
    assert(test_result == true);
    
    return 0;
}
#endif
