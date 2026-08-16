/*@
    predicate valid_k(integer k) = 1 <= k && k <= 100000;
    predicate loop_inv(integer k, integer i, integer a, integer result) =
        valid_k(k) &&
        1 <= i && i <= k + 1 &&
        0 <= a && a < k &&
        0 <= result && result <= k;
*/

/*@
    requires valid_k(k);
    ensures 0 <= \result && \result <= k;
    assigns \nothing;
*/
int func(int k)
{
    int a;
    int result;
    int i;

    a = 7 % k;
    result = 0;
    i = 1;

    /*@
        loop invariant loop_inv(k, i, a, result);
        loop assigns a, result, i;
        loop variant k - i;
    */
    while (i <= k)
    {
        if (a == 0)
        {
            result = i;
            break;
        }
        else
        {
            a = (a * 10 + 7) % k;
            i = i + 1;
        }
    }
    return result;
}
