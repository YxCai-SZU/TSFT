/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int count;
    int temp_n;
    int i;

    count = 0;
    temp_n = n;
    i = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= i <= ((n) / 3);
        loop invariant count == 0;
        loop invariant temp_n == n - 3 * i;
        loop assigns temp_n, i;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n = temp_n - 3;
        i = i + 1;
    }

    count = i;

    //@ assert count == ((n) / 3);
    return count;
}
