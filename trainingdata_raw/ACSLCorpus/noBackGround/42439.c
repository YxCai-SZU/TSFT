/*@
    requires (0 <= (n) && (n) < 1000000000);
    ensures ((\result) <= 9);
*/
unsigned int max_digit(unsigned int n)
{
    unsigned int max = 0;
    unsigned int temp = n;
    
    /*@
        loop invariant 0 <= temp <= n;
        loop invariant max <= 9;
        loop invariant 0 <= n < 1000000000;
        loop assigns temp, max;
    */
    while (temp > 0)
    {
        unsigned int current_digit = temp % 10;
        if (current_digit > max)
        {
            max = current_digit;
        }
        temp /= 10;
    }
    
    //@ assert max <= 9;
    return max;
}
