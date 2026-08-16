/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    int divisor;

    result = n * 800;
    temp_n = n;
    count = 0;
    divisor = 15;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant temp_n == n - count * 15;
        loop invariant result == n * 800;
        loop invariant 0 <= temp_n;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= divisor)
    {
        temp_n -= divisor;
        count += 1;
    }

    //@ assert 0 <= count * 200 && count * 200 <= 200 * 6;

    result -= count * 200;
    return result;
}
