#include <stdint.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 9;

    //@ lemma result_zero: \forall integer x, a; in_range(x) && in_range(a) && x < a ==> func(x, a) == 0;
    //@ lemma result_ten: \forall integer x, a; in_range(x) && in_range(a) && x >= a ==> func(x, a) == 10;
*/


int64_t func(int64_t x, int64_t a)
{
    int64_t result;
    //@ assert in_range(x);
    //@ assert in_range(a);
    
    if (x < a)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = 10;
        //@ assert result == 10;
    }
    
    //@ assert (x < a ==> result == 0) && (x >= a ==> result == 10);
    return result;
}

#ifdef TEST
#include <assert.h>

void test_input1(void)
{
    int64_t x = 5;
    int64_t a = 8;
    int64_t result = func(x, a);
    //@ assert result == 0;
    assert(result == 0);
}

void test_input2(void)
{
    int64_t x = 9;
    int64_t a = 5;
    int64_t result = func(x, a);
    //@ assert result == 10;
    assert(result == 10);
}
#endif
