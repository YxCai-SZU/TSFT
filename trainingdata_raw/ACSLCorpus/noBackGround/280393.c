#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (w >= s);
*/
bool func(long s, long w)
{
    // Declare all variables at the top
    bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    result = (w >= s);
    
    //@ assert result == (w >= s);
    return result;
}

/*@
    requires (1 <= (s) <= 100);
    requires (1 <= (w) <= 100);
    ensures \result == (w >= s);
*/
bool func2(long s, long w)
{
    // Declare all variables at the top
    bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;
    
    result = (w >= s);
    
    //@ assert result == (w >= s);
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    // Test cases
    assert(func(10, 15) == true);
    assert(func2(10, 15) == true);
    return 0;
}
#endif
