#include <stdbool.h>

/*@
    requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    result = c - a + b;
    //@ assert result == c - a + b;
    if (result > 0)
    {
        //@ assert result <= c;
        return result;
    }
    else
    {
        return 0;
    }
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(5, 3, 5) == 3);
    assert(func(5, 3, 2) == 0);
    return 0;
}
#endif
