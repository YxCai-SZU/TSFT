/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((((n)) / 2) + (((n)) % 2));
    assigns \nothing;
*/
int func(int n)
{
    int half = 0;
    int temp_n = n;
    int is_even = 0;
    int result;

    /*@
        loop invariant 0 <= half <= ((n) / 2);
        loop invariant 0 <= temp_n;
        loop invariant temp_n + 2 * half == n;
        loop assigns half, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        half += 1;
        temp_n -= 2;
    }

    if (temp_n == 1)
    {
        is_even = 1;
    }

    //@ assert half == ((n) / 2);
    //@ assert is_even == ((n) % 2);
    
    result = half + is_even;
    
    //@ assert result == ((((n)) / 2) + (((n)) % 2));
    
    return result;
}
