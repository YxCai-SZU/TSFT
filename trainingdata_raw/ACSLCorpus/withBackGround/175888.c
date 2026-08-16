/*@
    predicate valid_range(integer x) = 1 <= x <= 3;
    predicate distinct(integer a, integer b) = a != b;
    predicate sum_condition(integer r, integer a, integer b) = r + a + b == 6;
    predicate result_range(integer r) = 1 <= r <= 6;
*/

/*@
    requires valid_range(a) && valid_range(b) && distinct(a, b);
    ensures sum_condition(\result, a, b) && result_range(\result);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a) && valid_range(b) && distinct(a, b);
    result = 6 - a - b;
    //@ assert sum_condition(result, a, b);
    //@ assert result_range(result);
    return result;
}
