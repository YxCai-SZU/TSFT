#include <stdbool.h>
/*@
    predicate valid_params(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    predicate result_condition(integer a, integer b, integer result) =
        result <= a &&
        (result == 0 || (b % a == 0 ==> result == a) || (b % a != 0 ==> result == a - 1));

    lemma result_bound: \forall integer a, b, result;
        valid_params(a, b) && result_condition(a, b, result) ==> result <= a;
*/

/*@
    requires valid_params(a, b);
    ensures \result <= a;
    ensures result_condition(a, b, \result);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result = 0;
    //@ assert valid_params(a, b);

    if (b % a == 0) {
        result = a;
    } else {
        result = a - 1;
    }
    //@ assert result_condition(a, b, result);

    unsigned int i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant valid_params(a, b);
        loop invariant result_condition(a, b, result);
        loop assigns i;
        loop variant 1 - i;
    */
    while (i < 1) {
        //@ assert 0 <= i <= 1;
        i += 1;
    }

    //@ assert result <= a;
    //@ assert result_condition(a, b, result);
    return result;
}
