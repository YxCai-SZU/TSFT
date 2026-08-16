#include <limits.h>

/*@
    predicate valid_input(integer i) = 1 <= i <= 10;

    logic integer inner_expr(integer i) = 1 + i * (1 + i);
    logic integer result_expr(integer i) = i * inner_expr(i);

    lemma inner_expr_bounds:
        \forall integer i; valid_input(i) ==> 1 <= inner_expr(i) <= 111;

    lemma result_expr_bounds:
        \forall integer i; valid_input(i) ==> 1 <= result_expr(i) <= 1110;
*/

/*@
    requires valid_input(input);
    ensures \result == result_expr(input);
    ensures 1 <= \result <= 1110;
*/
int func(int input)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= input && input <= 10;
    //@ assert 1 <= inner_expr(input) <= 111;
    //@ assert 1 <= result_expr(input) <= 1110;

    result = input * (1 + input * (1 + input));
    
    //@ assert result == result_expr(input);
    return result;
}
