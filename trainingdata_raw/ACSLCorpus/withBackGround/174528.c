#include <stdbool.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;

    logic integer complement(integer x) = 1 - x;

    lemma complement_zero: \forall integer x; is_zero(x) ==> complement(x) == 1;
    lemma complement_one: \forall integer x; is_one(x) ==> complement(x) == 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures \result == complement(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert x == 0 || x == 1;
    
    if (x == 0) {
        //@ assert is_zero(x);
        result = 1;
        //@ assert result == complement(x);
        return result;
    } else {
        //@ assert is_one(x);
        result = 0;
        //@ assert result == complement(x);
        return result;
    }
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int func_0(void)
{
    int result;
    result = 0;
    //@ assert result == 0;
    return result;
}

/*@
    ensures \result == 1;
    assigns \nothing;
*/
int func_1(void)
{
    int result;
    result = 1;
    //@ assert result == 1;
    return result;
}
