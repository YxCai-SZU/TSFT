/*@
    requires y != 0;
    ensures \result <= x;
    assigns \nothing;
*/
unsigned int verify_div_ordered_by_denominator(unsigned int x, unsigned int y)
{
    //@ assert y != 0;
    //@ assert x / y <= x;
    return x / y;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    unsigned int x;
    unsigned int y;
    
    x = 10;
    y = 2;
    verify_div_ordered_by_denominator(x, y);
    
    return 0;
}
