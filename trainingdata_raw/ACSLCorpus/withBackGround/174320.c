/*@
    predicate is_even_property(integer n, integer result) =
        (result == 1) <==> (n % 2 == 0);
    predicate greater_than_threshold_property(integer n, integer threshold, integer result) =
        (result == 1) <==> (n > threshold);
*/

/*@
    requires 0 <= n <= 4294967295;
    ensures \result == 1 <==> n % 2 == 0;
    assigns \nothing;
*/
int is_even(unsigned int n)
{
    // Variable declarations
    int result;

    //@ assert n >= 0 && n <= 4294967295;
    //@ assert n % 2 == n - 2 * (n / 2);

    result = (n % 2 == 0) ? 1 : 0;
    //@ assert is_even_property(n, result);
    return result;
}

/*@
    requires 0 <= n <= 4294967295 && 0 <= threshold <= 4294967295;
    ensures \result == 1 <==> n > threshold;
    assigns \nothing;
*/
int greater_than_threshold(unsigned int n, unsigned int threshold)
{
    // Variable declarations
    int result;

    result = (n > threshold) ? 1 : 0;
    //@ assert greater_than_threshold_property(n, threshold, result);
    return result;
}
