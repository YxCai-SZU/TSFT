/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer compute_result(integer a, integer b, integer c, integer d) =
        a < b ? a + c : b + d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result == compute_result(a, b, c, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a < b) {
        result = a + c;
    } else {
        result = b + d;
    }
    
    //@ assert result == compute_result(a, b, c, d);
    //@ assert result >= 0;
    
    return result;
}
