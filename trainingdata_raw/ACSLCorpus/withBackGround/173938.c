#include <stdint.h>

/*@
    predicate is_mod3_zero(integer a) = a % 3 == 0;
    predicate is_mod5_zero(integer b) = b % 5 == 0;

    logic integer func_result(integer a, integer b) =
        (a % 3 == 0 && b % 5 == 0) ? -1 :
        (a % 3 != 0 && b % 5 != 0) ? 1 : 0;

    lemma result_range: \forall integer a, b;
        1 <= a <= 20 && 1 <= b <= 20 ==>
        func_result(a, b) == -1 || func_result(a, b) == 0 || func_result(a, b) == 1;

    lemma result_neg1_implies: \forall integer a, b;
        1 <= a <= 20 && 1 <= b <= 20 && func_result(a, b) == -1 ==>
        a % 3 == 0 && b % 5 == 0;

    lemma result_1_implies: \forall integer a, b;
        1 <= a <= 20 && 1 <= b <= 20 && func_result(a, b) == 1 ==>
        a % 3 != 0 && b % 5 != 0;

    lemma result_0_implies: \forall integer a, b;
        1 <= a <= 20 && 1 <= b <= 20 && func_result(a, b) == 0 ==>
        (a % 3 == 0 && b % 5 != 0) || (a % 3 != 0 && b % 5 == 0);
*/

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == -1 || \result == 0 || \result == 1;
    ensures \result == -1 ==> (a % 3 == 0 && b % 5 == 0);
    ensures \result == 1 ==> (a % 3 != 0 && b % 5 != 0);
    ensures \result == 0 ==> ((a % 3 == 0 && b % 5 != 0) || (a % 3 != 0 && b % 5 == 0));
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    if (a % 3 == 0 && b % 5 == 0)
    {
        result = -1;
        //@ assert result == -1;
    }
    else if (a % 3 != 0 && b % 5 != 0)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }
    
    return result;
}
