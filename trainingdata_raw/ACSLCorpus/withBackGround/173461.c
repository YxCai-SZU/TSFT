/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 1000000000 &&
        0 <= b && b <= 1000000000 &&
        0 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    predicate output_bounds(integer res, integer a, integer c, integer k) =
        res >= -1 * c &&
        res <= 1 * a &&
        res <= k;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures output_bounds(\result, a, c, k);
*/
long func(long a, long b, long c, long k)
{
    long sum;
    long rst;

    sum = 0;
    rst = k;

    //@ assert sum == 0 && rst == k;

    if (a >= rst)
    {
        sum += rst;
        rst -= rst;
        //@ assert rst == 0;
    }
    else
    {
        sum += a;
        rst -= a;
        //@ assert rst == k - a;
    }

    //@ assert sum >= 0 && sum <= a && sum <= k;

    if (b >= rst)
    {
        rst -= rst;
        //@ assert rst == 0;
    }
    else
    {
        rst -= b;
        //@ assert rst == k - a - b;
    }

    //@ assert rst >= 0 && rst <= k;

    sum -= rst;

    //@ assert sum >= -1 * c;
    //@ assert sum <= 1 * a;
    //@ assert sum <= k;

    return sum;
}
