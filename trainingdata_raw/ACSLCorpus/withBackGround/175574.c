#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer func_result(integer a, integer b) =
        a * b - a - b + 1;

    lemma result_positive:
        \forall integer a, b;
        valid_params(a, b) ==> func_result(a, b) > 0;

    lemma no_overflow:
        \forall integer a, b;
        valid_params(a, b) ==> a * b <= 10000;
*/

/*@
    requires valid_params(a, b);
    ensures \result == func_result(a, b);
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert a * b <= 10000;
    //@ assert a + b >= 4;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -99;
    //@ assert a * b - a - b + 1 > 0;
    //@ assert a * b - a - b + 1 == a * b - a - b + 1;

    result = a * b - a - b + 1;
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Variable declarations at top of scope
    uint32_t res1, res2, res3, res4, res5;
    
    res1 = func(2, 2);
    assert(res1 == 1);
    
    res2 = func(5, 7);
    assert(res2 == 24);
    
    res3 = func(10, 11);
    assert(res3 == 96);
    
    res4 = func(2, 100);
    assert(res4 == 1);
    
    res5 = func(100, 2);
    assert(res5 == 1);
    
    return 0;
}
#endif
