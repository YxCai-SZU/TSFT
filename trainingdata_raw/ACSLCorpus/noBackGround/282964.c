/*@
    requires (1 <= (x) <= 179);
    ensures \result == (x / 3) * 3 + (x % 3);
*/
int func(int x)
{
    int quotient = 0;
    int remainder = x;
    int divisor = 3;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / divisor;
        loop invariant remainder == x - quotient * divisor;
        loop invariant remainder >= 0;
        loop invariant (1 <= (x) <= 179);
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == x - quotient * divisor;
    }
    
    //@ assert remainder == x % divisor;
    //@ assert quotient == x / divisor;
    
    return quotient * 3 + remainder;
}

int main()
{
    return 0;
}
