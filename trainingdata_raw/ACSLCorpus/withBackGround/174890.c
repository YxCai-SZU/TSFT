/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= k && k <= 100;

    logic integer compute_result(integer a, integer k) =
        a < k ? k - a : 0;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result == compute_result(a, k);
*/
long func(long a, long b, long c, long k)
{
    long result = 0;

    //@ assert valid_params(a, b, c, k);
    
    if (k > a)
    {
        result += k - a;
        //@ assert result == k - a;
    }
    else
    {
        result += 0;
        //@ assert result == 0;
    }

    //@ assert result == compute_result(a, k);
    return result;
}
