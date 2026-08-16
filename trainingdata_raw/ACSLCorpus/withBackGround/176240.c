#include <limits.h>

/*@
    predicate is_valid_x(integer x) = 0 <= x <= 1;
*/

/*@
    requires is_valid_x(x);
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert is_valid_x(x);
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/*@
    logic integer func2_logic(integer x) = (x == 0) ? 1 : 0;
*/

/*@
    lemma func2_lemma_zero:
        \forall integer x; is_valid_x(x) && x == 0 ==> func2_logic(x) == 1;
    lemma func2_lemma_one:
        \forall integer x; is_valid_x(x) && x == 1 ==> func2_logic(x) == 0;
*/

/*@
    requires is_valid_x(x);
    ensures \result == func2_logic(x);
    assigns \nothing;
*/
int func2(int x)
{
    int result;
    //@ assert is_valid_x(x);
    if (x == 0) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
    }
    return result;
}
