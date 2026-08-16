/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int result = 0;
    unsigned int remaining = n;
    unsigned int two = 2;
    
    /*@
        loop invariant 0 <= result <= n / 2;
        loop invariant 0 <= remaining <= n;
        loop invariant result * two + remaining == n;
        loop invariant (1 <= (n) <= 100);
        loop assigns remaining, result;
        loop variant remaining;
    */
    while (remaining >= two)
    {
        //@ assert remaining >= two;
        remaining -= two;
        result += 1;
    }
    
    if (remaining == 1)
    {
        result += 1;
    }
    
    //@ assert result == (((n) + 1) / 2);
    return result;
}

int main()
{
    return 0;
}
