/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    ensures \result == ((c) > (a) - (b) ? (a) - (b) + (c) : 0);
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (c > a - b)
    {
        //@ assert a - b + c >= 0;
        result = a - b + c;
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result == ((c) > (a) - (b) ? (a) - (b) + (c) : 0);
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    assert(func(10, 3, 2) == 0);
    assert(func(10, 2, 5) == 3);
    assert(func(10, 10, 10) == 10);
    assert(func(5, 2, 1) == 0);
    assert(func(1, 1, 20) == 20);
    assert(func(20, 1, 1) == 0);
    assert(func(10, 10, 1) == 1);
    assert(func(1, 10, 1) == 0);
    return 0;
}
#endif
