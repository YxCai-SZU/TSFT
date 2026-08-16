/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int res;
    unsigned int i;
    
    i = 0;
    /*@
        loop invariant i <= 1;
        loop assigns i;
    */
    while (i < 1)
    {
        i = i + 1;
    }
    
    //@ assert 1 <= a * b <= 10000;
    
    res = a * b;
    return res;
}
