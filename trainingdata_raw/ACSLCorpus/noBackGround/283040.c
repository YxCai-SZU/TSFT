/*@
    requires 1 <= n <= 100;
    ensures \result == n * 800 - 200 * (n / 15);
    assigns \nothing;
*/
unsigned long func(unsigned long n)
{
    unsigned long result;
    unsigned long count;
    unsigned long temp_n;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant (0 <= (temp_n) <= (n) &&
        0 <= (count) <= (n) / 15 &&
        (temp_n) == (n) - 15 * (count));
        loop invariant result == n * 800;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count += 1;
        temp_n -= 15;
        //@ assert temp_n == n - 15 * count;
    }
    
    //@ assert count == n / 15;
    result -= count * 200;
    //@ assert result == ((n) * 800 - 200 * (count));
    return result;
}
