/*@
    predicate half_invariant(integer n, integer temp_n, integer half, integer count) =
        0 <= temp_n <= n &&
        half <= n / 2 &&
        temp_n == n - 2 * half &&
        count == (n - temp_n) / 2;

    logic integer func_result(integer n) = n / 2 + n % 2;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == func_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int half;
    int temp_n;
    int count;
    int remainder;
    int result;

    half = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant half_invariant(n, temp_n, half, count);
        loop invariant 0 <= temp_n;
        loop assigns half, temp_n, count;
        loop variant temp_n;
    */
    while (temp_n > 1)
    {
        half += 1;
        temp_n -= 2;
        count += 1;
    }

    if (temp_n == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }

    //@ assert half == n / 2;
    //@ assert remainder == n % 2;

    result = half + remainder;
    return result;
}
