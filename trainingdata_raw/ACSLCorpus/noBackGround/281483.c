#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (a) <= 10);
    
    //@ assert 1 <= a * a <= 100;
    //@ assert 1 <= a * a * a <= 1000;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Variable declarations at top of scope
    int32_t test1;
    int32_t test2;
    int32_t test3;
    
    test1 = func(5);
    assert(test1 == 155);
    
    test2 = func(10);
    assert(test2 == 1110);
    
    test3 = func(1);
    assert(test3 == 3);
    
    return 0;
}
#endif
