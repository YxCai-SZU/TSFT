/*@
    predicate is_valid_input(integer x) = x == 0 || x == 1;
    predicate is_within_i64_range(integer x) = x >= -9223372036854775808 && x <= 9223372036854775807;
*/

/*@
    requires is_valid_input(x);
    requires is_within_i64_range(x);
    ensures \result == 1 - x;
    assigns \nothing;
*/
long func(long x)
{
    long result;
    //@ assert x == 0 || x == 1;
    //@ assert x >= -9223372036854775808 && x <= 9223372036854775807;
    result = 1 - x;
    return result;
}
