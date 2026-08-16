/*@
    predicate is_in_range(integer x) = -100 <= x && x <= 100;
    predicate result_condition(integer a, integer b, integer c, integer r) =
        r == (a < b && b < c);
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures result_condition(a, b, c, \result);
    assigns \nothing;
*/
_Bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);

    result = 0;
    if (a < b) {
        if (b < c) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    return result;
}
