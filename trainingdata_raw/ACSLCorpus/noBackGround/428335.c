/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == (t / a) * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int t)
{
    unsigned int tmp;
    
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    //@ assert (1 <= (t) <= 20);
    
    tmp = t / a;
    
    //@ assert tmp == t / a;
    //@ assert tmp * b <= 400;
    
    return tmp * b;
}
