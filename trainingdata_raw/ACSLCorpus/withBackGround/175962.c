/*@
    predicate non_negative_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 &&
        k >= 1 && k <= a + b + c && k <= 2000000000;
*/

/*@
    requires non_negative_params(a, b, c, k);
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_flag;
    int counter;
    int i;

    k_flag = 0;
    counter = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= a;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= counter <= i;
        loop invariant non_negative_params(a, b, c, k);
        loop assigns k_flag, counter, i;
        loop variant a - i;
    */
    while (i < a)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag += 1;
        counter += 1;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= b;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= counter <= a;
        loop invariant non_negative_params(a, b, c, k);
        loop assigns k_flag, i;
        loop variant b - i;
    */
    while (i < b)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag += 1;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= c;
        loop invariant 0 <= k_flag <= k;
        loop invariant 0 <= counter <= a;
        loop invariant non_negative_params(a, b, c, k);
        loop assigns k_flag, i;
        loop variant c - i;
    */
    while (i < c)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag += 1;
        i += 1;
    }

    return counter;
}
