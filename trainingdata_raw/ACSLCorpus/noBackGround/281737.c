/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == n/2 + n%2;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int result;
    unsigned int temp_n;
    unsigned int count;
    unsigned int remainder;
    
    // Division by 2 implementation
    result = 0;
    temp_n = n;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 2 * count;
        loop invariant 0 <= count <= n/2;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    result = count;
    
    // Modulo 2 implementation
    remainder = n;
    
    /*@
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n - 2 * (n/2 - remainder/2);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        remainder -= 2;
    }
    
    if (remainder == 1)
    {
        result += 1;
    }
    
    //@ assert result == n/2 + n%2;
    return result;
}
