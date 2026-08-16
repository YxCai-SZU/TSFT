/*@
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate c_le_d(integer c, integer d) = c <= d;
    predicate result_nonneg(integer r) = r >= 0;
    predicate result_le_b_minus_a(integer r, integer a, integer b) = r <= b - a;
    predicate result_le_d_minus_c(integer r, integer c, integer d) = r <= d - c;
*/

/*@
    requires 0 <= a && a <= 10000;
    requires 0 <= b && b <= 10000;
    requires 0 <= c && c <= 10000;
    requires 0 <= d && d <= 10000;
    requires a_le_b(a, b);
    requires c_le_d(c, d);
    ensures result_nonneg(\result);
    ensures result_le_b_minus_a(\result, a, b);
    ensures result_le_d_minus_c(\result, c, d);
*/
int func(int a, int b, int c, int d)
{
    int begin;
    int end;
    int result;

    if (a > c)
        begin = a;
    else
        begin = c;

    if (b < d)
        end = b;
    else
        end = d;

    if (end > begin)
        result = end - begin;
    else
        result = 0;

    //@ assert result_nonneg(result);
    //@ assert result_le_b_minus_a(result, a, b);
    //@ assert result_le_d_minus_c(result, c, d);

    return result;
}
