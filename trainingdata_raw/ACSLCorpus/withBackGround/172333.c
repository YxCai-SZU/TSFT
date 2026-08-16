/*@
    predicate m_le_5(integer m) = m <= 5;
    predicate m_gt_5(integer m) = m > 5;
    logic integer compute_result(integer n, integer m) =
        m <= 5 ? 0 : n - m + 1;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (m <= 5 ==> \result == 0) && (m > 5 ==> \result == n - m + 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    if (m > 5)
    {
        result = n - m + 1;
    }
    else
    {
        result = 0;
    }

    //@ assert (m <= 5 ==> result == 0) && (m > 5 ==> result == n - m + 1);
    return result;
}
