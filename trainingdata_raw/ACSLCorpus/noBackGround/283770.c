#include <limits.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == (((C) > ((A) - (B))) ? ((C) - ((A) - (B))) : 0);
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int diff;
    int result;

    diff = A - B;
    //@ assert diff == A - B;

    if (C > diff)
    {
        result = C - diff;
        //@ assert result == C - diff;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }

    //@ assert result == (((C) > ((A) - (B))) ? ((C) - ((A) - (B))) : 0);
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(5, 3, 5) == 3);
    assert(func(10, 2, 3) == 0);
    assert(func(1, 1, 10) == 10);
    assert(func(20, 10, 5) == 0);
    assert(func(7, 3, 2) == 0);
    assert(func(1, 1, 1) == 1);
    return 0;
}
#endif
