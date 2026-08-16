/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0 && (\result) <= (a) && ((\result) == (a) - (b) * 2 || (\result) == 0));
*/
int func(int a, int b)
{
    //@ assert b * 2 <= 200;
    //@ assert a - b * 2 >= -10000;

    if (a > b * 2)
    {
        return a - b * 2;
    }
    else
    {
        return 0;
    }
}

/*@
    requires (1 <= (a) && (a) <= 100 && 1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0 && (\result) <= (a) && ((\result) == (a) - (b) * 2 || (\result) == 0));
*/
int func_input_checking(int a, int b)
{
    //@ assert b * 2 <= 200;
    //@ assert a - b * 2 >= -10000;

    if (a > b * 2)
    {
        //@ assert a - b * 2 >= 0;
        //@ assert a - b * 2 <= a;
        return a - b * 2;
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
    assert(func(10, 3) == 4);
    assert(func(1, 1) == 0);
    assert(func(5, 3) == 0);
    assert(func(10, 1) == 8);
    
    assert(func_input_checking(10, 3) == 4);
    assert(func_input_checking(1, 1) == 0);
    assert(func_input_checking(5, 3) == 0);
    assert(func_input_checking(10, 1) == 8);
    
    return 0;
}
#endif
