/*@
    predicate count_constraint(integer temp_n, integer n, integer count) =
        0 <= temp_n <= n &&
        0 <= count <= n / 15 &&
        temp_n == n - 15 * count;

    logic integer final_result(integer n, integer count) =
        800 * n - 200 * count;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == 800 * n - 200 * (n / 15);
    assigns \nothing;
*/
int func(int n)
{
    int res;
    int count;
    int temp_n;

    res = 800 * n;
    count = 0;
    temp_n = n;

    /*@
        loop invariant count_constraint(temp_n, n, count);
        loop assigns count, temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - 15 * count;
    }

    //@ assert count == n / 15;
    res = res - 200 * count;
    //@ assert res == final_result(n, count);
    return res;
}
