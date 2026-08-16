/*@
    predicate non_negative(integer x) = x >= 0;
    predicate k_in_range(integer a, integer b, integer c, integer k) =
        1 <= k <= a + b + c;
    predicate result_bounded(integer result, integer k) =
        result <= k && result >= -k;
*/

/*@
    requires non_negative(a) && non_negative(b) && non_negative(c);
    requires k_in_range(a, b, c, k);
    ensures result_bounded(\result, k);
*/
long func(long a, long b, long c, long k)
{
    long result;
    long count;
    long remaining_k;

    result = 0;
    count = 0;
    remaining_k = k;

    if (a >= remaining_k) {
        result += remaining_k;
        remaining_k = 0;
    } else {
        result += a;
        remaining_k -= a;
    }

    if (b >= remaining_k) {
        remaining_k = 0;
    } else {
        remaining_k -= b;
    }

    if (c >= remaining_k) {
        result -= remaining_k;
        remaining_k = 0;
    } else {
        result -= c;
        remaining_k -= c;
    }

    //@ assert result <= k;
    //@ assert result >= -k;

    return result;
}
