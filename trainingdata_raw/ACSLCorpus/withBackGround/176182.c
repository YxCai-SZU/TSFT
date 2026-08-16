#include <stdint.h>
/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer expected_result(integer a, integer b) =
        (a + b + 1) / 2;

    lemma result_positive: \forall integer a, b; valid_input(a, b) ==> expected_result(a, b) >= 1;
*/
/*@
    requires valid_input(a, b);
    ensures \result == expected_result(a, b);
    ensures \result >= 1;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t avg;

    //@ assert valid_input(a, b);
    sum = a + b;
    //@ assert sum >= 2 && sum <= 200;
    avg = (sum + 1) / 2;
    //@ assert avg >= 1;
    //@ assert avg == expected_result(a, b);
    return avg;
}

#ifdef TESTING
#include <assert.h>
int main()
{
    uint32_t result;
    
    result = func(5, 3);
    //@ assert result == 4;
    assert(result == 4);
    
    result = func(11, 19);
    //@ assert result == 15;
    assert(result == 15);
    
    result = func(50, 50);
    //@ assert result == 50;
    assert(result == 50);
    
    return 0;
}
#endif
