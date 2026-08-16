/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 10;
    logic integer inner_expr(integer x) = 1 + x * (1 + x);
    logic integer final_result(integer x) = x * inner_expr(x);
    lemma inner_expr_bounds: \forall integer x; x_in_range(x) ==> 1 <= inner_expr(x) && inner_expr(x) <= 111;
    lemma final_result_bounds: \forall integer x; x_in_range(x) ==> 1 <= final_result(x) && final_result(x) <= 1110;
*/

/*@
    requires x_in_range(x);
    ensures \result == final_result(x);
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int result;

    //@ assert x_in_range(x);
    //@ assert 1 <= inner_expr(x) && inner_expr(x) <= 111;
    //@ assert 1 <= final_result(x) && final_result(x) <= 1110;

    result = x * (1 + x * (1 + x));
    return result;
}
