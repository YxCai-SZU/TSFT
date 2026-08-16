#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result == (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    
    if (x < a || x > a + b)
    {
        //@ assert x < a || x > a + b;
        result = false;
    }
    else
    {
        //@ assert x >= a && x <= a + b;
        result = true;
    }
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test case 1
    bool res1 = func(1, 2, 3);
    //@ assert res1 == true;
    assert(res1 == true);
    
    // Test case 2
    bool res2 = func(1, 2, 5);
    //@ assert res2 == false;
    assert(res2 == false);
    
    return 0;
}
#endif
