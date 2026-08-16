/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (((n)) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int quotient;

    result = 0;
    temp_n = n;
    result = n * 800;
    quotient = 0;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((n) / 15);
        loop invariant temp_n == n - quotient * 15;
        loop invariant result == n * 800;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n = temp_n - 15;
        quotient = quotient + 1;
    }

    result = result - quotient * 200;
    return result;
}
