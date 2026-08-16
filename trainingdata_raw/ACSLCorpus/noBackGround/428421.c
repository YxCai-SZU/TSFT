/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (a * 8) / 100 == b;
    ensures \result == 0 ==> (a * 8) / 100 != b;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    unsigned int product;
    unsigned int quotient = 0;
    unsigned int remainder;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    //@ assert ((a) * 8) <= 800;
    product = a * 8;
    remainder = product;
    
    /*@
        loop invariant (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
        loop invariant 0 <= quotient <= product / 100;
        loop invariant remainder == product - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        quotient += 1;
        remainder -= 100;
    }
    
    //@ assert quotient == (a * 8) / 100;
    
    if (quotient == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
