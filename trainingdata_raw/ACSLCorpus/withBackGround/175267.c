#include <stdbool.h>

/*@
    predicate shifted_in_range(integer a, integer b) =
        -100 <= a <= 100 && -100 <= b <= 100;

    logic integer shifted_value(integer x) = x + 100;

    lemma shift_preserves_order:
        \forall integer a, b;
            shifted_in_range(a, b) ==>
            (shifted_value(a) <= shifted_value(b) ==> a <= b);
*/

/*@
    requires shifted_in_range(a, b);
    ensures \result == (a <= b);
*/
bool func(int a, int b)
{
    int a_new;
    int b_new;
    int result;
    bool final_result;

    a_new = a + 100;
    b_new = b + 100;

    //@ assert a_new == shifted_value(a);
    //@ assert b_new == shifted_value(b);

    if (a_new <= b_new) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert result == 1 ==> a_new <= b_new;
    //@ assert result == 0 ==> a_new > b_new;

    final_result = (result == 1);

    //@ assert final_result == (a_new <= b_new);
    //@ assert final_result ==> a <= b;
    //@ assert !final_result ==> a > b;

    return final_result;
}
