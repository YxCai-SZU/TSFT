/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    unsigned int pi = 3;
    unsigned int circumference;
    
    //@ assert 2 * 3 * r == 2 * pi * r;
    
    circumference = 2 * pi * r;
    return circumference;
}
