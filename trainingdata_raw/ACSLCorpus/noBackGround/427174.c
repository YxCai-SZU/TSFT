/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 314 * r) / 100;
    assigns \nothing;
*/
long func(long r)
{
    long precision_factor;
    long pi;
    long product;
    long result;
    long remainder;
    
    precision_factor = 100;
    pi = 314;
    
    product = 2 * pi * r;
    //@ assert product == 2 * 314 * r;
    
    result = 0;
    remainder = product;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant result * 100 + remainder == product;
        loop invariant 0 <= remainder < product + 100;
        loop invariant result <= product / 100;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= precision_factor)
    {
        //@ assert remainder >= 100;
        result = result + 1;
        remainder = remainder - precision_factor;
        //@ assert result * 100 + remainder == product;
    }
    
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
