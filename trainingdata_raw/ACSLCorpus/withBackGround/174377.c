#include <stdbool.h>

/*@
    predicate within_range(integer a, integer b, integer c) =
        a <= c && c <= b;
*/

/*@
    requires a <= b;
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result = false;
    
    //@ assert a <= b;
    
    if (a <= c && c <= b)
    {
        result = true;
    }
    
    //@ assert result == (a <= c && c <= b);
    
    return result;
}

/* Test cases (not part of verification) */
#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(1, 1, 1) == true);
    assert(func(1, 2, 3) == false);
    assert(func(1, 3, 2) == false);
    assert(func(1, 3, 4) == false);
    return 0;
}
#endif
