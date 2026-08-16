#include <stdint.h>

/*@
    predicate both_small(integer a, integer b) =
        a < 10 && b < 10;

    predicate one_large(integer a, integer b) =
        a >= 10 || b >= 10;

    lemma both_small_implies_result_one:
        \forall integer a, b;
            1 <= a <= 20 && 1 <= b <= 20 && both_small(a, b) ==>
            a < 10 && b < 10;

    lemma one_large_implies_result_zero:
        \forall integer a, b;
            1 <= a <= 20 && 1 <= b <= 20 && one_large(a, b) ==>
            a >= 10 || b >= 10;
*/

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (a < 10 && b < 10);
    ensures \result == 0 ==> (a >= 10 || b >= 10);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    //@ assert 1 <= a <= 20 && 1 <= b <= 20;
    
    if (a < 10 && b < 10)
    {
        //@ assert a < 10 && b < 10;
        result = 1;
    }
    else
    {
        //@ assert a >= 10 || b >= 10;
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}
