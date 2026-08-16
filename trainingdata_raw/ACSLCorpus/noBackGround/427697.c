/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100 && (m) <= (n));
    ensures \result == n - (m * 2) || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    int temp_n;
    int temp_m;
    int count;

    result = 0;
    temp_n = n;
    temp_m = m;
    count = 0;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= m <= 100;
        loop invariant m <= n;
        loop invariant temp_n == n - 2 * count;
        loop invariant temp_m == m - count;
        loop invariant 0 <= count <= m;
        loop assigns temp_n, temp_m, count;
        loop variant temp_m;
    */
    while (temp_m > 0)
    {
        //@ assert temp_m > 0;
        temp_n = temp_n - 2;
        temp_m = temp_m - 1;
        count = count + 1;
    }

    if (temp_n > 0)
    {
        result = temp_n;
    }
    else
    {
        result = 0;
    }

    //@ assert result == n - (m * 2) || result == 0;
    return result;
}
