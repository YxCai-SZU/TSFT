#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100);
    ensures \result == ((k) * (k) * (k));
    assigns \nothing;
*/
int func(int k)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert 1 <= k && k <= 100;
    //@ assert k * k <= 10000;
    //@ assert k * k * k <= 1000000;
    
    result = k * k * k;
    //@ assert result == ((k) * (k) * (k));
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    // Variable declarations at scope top
    int test1, test2, test3;
    
    test1 = func(1);
    assert(test1 == 1);
    
    test2 = func(10);
    assert(test2 == 1000);
    
    test3 = func(100);
    assert(test3 == 1000000);
    
    return 0;
}
#endif
