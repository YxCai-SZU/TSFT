#include <limits.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 179;

    predicate result_one(integer x) = 1 <= x <= 35;
    predicate result_two(integer x) = 36 <= x <= 70;
    predicate result_three(integer x) = 71 <= x <= 105;
    predicate result_four(integer x) = 106 <= x <= 140;
    predicate result_five(integer x) = 141 <= x <= 179;

    logic integer func_result(integer x) =
        (1 <= x && x <= 35) ? 1 :
        (36 <= x && x <= 70) ? 2 :
        (71 <= x && x <= 105) ? 3 :
        (106 <= x && x <= 140) ? 4 :
        (141 <= x && x <= 179) ? 5 : 0;

    lemma result_range: \forall integer x; in_range(x) ==> 
        (func_result(x) == 1 || func_result(x) == 2 || func_result(x) == 3 || 
         func_result(x) == 4 || func_result(x) == 5);
*/

/*@
    requires in_range(x);
    ensures \result == 1 || \result == 2 || \result == 3 || \result == 4 || \result == 5;
    ensures \result == 1 ==> result_one(x);
    ensures \result == 2 ==> result_two(x);
    ensures \result == 3 ==> result_three(x);
    ensures \result == 4 ==> result_four(x);
    ensures \result == 5 ==> result_five(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;

    //@ assert in_range(x);
    
    if (x >= 1 && x <= 35) {
        result = 1;
        //@ assert result_one(x);
    } else if (x >= 36 && x <= 70) {
        result = 2;
        //@ assert result_two(x);
    } else if (x >= 71 && x <= 105) {
        result = 3;
        //@ assert result_three(x);
    } else if (x >= 106 && x <= 140) {
        result = 4;
        //@ assert result_four(x);
    } else if (x >= 141 && x <= 179) {
        result = 5;
        //@ assert result_five(x);
    } else {
        //@ assert 1 <= x && x <= 179;
        result = 0;
    }

    //@ assert result == func_result(x);
    return result;
}
