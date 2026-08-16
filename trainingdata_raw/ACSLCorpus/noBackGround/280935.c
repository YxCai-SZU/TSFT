/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (((n)) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int i;
    int temp_n;

    result = n * 800;
    i = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant 0 <= i && i <= n / 15;
        loop invariant temp_n == n - 15 * i;
        loop assigns temp_n, i;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n = temp_n - 15;
        i = i + 1;
    }

    //@ assert i == n / 15;
    result = result - i * 200;
    return result;
}
