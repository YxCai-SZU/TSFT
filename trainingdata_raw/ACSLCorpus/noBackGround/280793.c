#include <stdbool.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
*/
int func(int a, int b, int c)
{
    int min_val;
    int result;

    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    
    if (a - b < c)
    {
        min_val = a - b;
    }
    else
    {
        min_val = c;
    }

    //@ assert min_val == (((a) - (b)) < (c) ? ((a) - (b)) : (c));
    //@ assert min_val >= 0;

    if (min_val < 0)
    {
        //@ assert min_val < 0;
        result = 0;
    }
    else
    {
        //@ assert min_val >= 0;
        result = c - min_val;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    assert(func(5, 3, 2) == 0);
    assert(func(5, 3, 4) == 2);
    assert(func(5, 3, 3) == 1);
    assert(func(5, 3, 1) == 0);
    return 0;
}
#endif
