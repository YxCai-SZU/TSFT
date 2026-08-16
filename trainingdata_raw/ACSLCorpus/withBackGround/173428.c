/*@
    predicate is_square(integer x, integer r) = r == x * x;
    predicate within_range(integer x) = x * x <= 9223372036854775807;
*/

/*@
    requires within_range(x);
    ensures is_square(x, \result);
    assigns \nothing;
*/
long long func(long long x)
{
    long long result;
    
    //@ assert x * x >= 0;
    //@ assert x * x <= 9223372036854775807;
    
    result = x * x;
    
    //@ assert is_square(x, result);
    return result;
}
