/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((3) * (r) * (r));
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    unsigned int pi;
    unsigned int area;
    
    //@ assert (1 <= (r) && (r) <= 100);
    pi = 3;
    
    //@ assert pi * r <= 300;
    //@ assert ((pi) * (r) * (r)) <= 30000;
    
    area = pi * r * r;
    return area;
}
