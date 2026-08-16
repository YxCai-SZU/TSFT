#include <stdbool.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
int func(int x)
{
    //@ assert 0 <= x <= 1;
    int result = 1 - x;
    //@ assert result == (1 - (x));
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(0) == 1);
    assert(func(1) == 0);
    return 0;
}
#endif
