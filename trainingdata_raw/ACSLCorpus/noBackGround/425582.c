/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((((a)) * ((a)) * ((a))) + (((a)) * ((a))) + (a));
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int a_pow2;
    unsigned int a_pow3;
    unsigned int an;
    
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert ((a) * (a)) <= 100;
    
    a_pow2 = a * a;
    
    //@ assert ((a) * (a) * (a)) <= 1000;
    
    a_pow3 = a * a * a;
    an = a_pow3 + a_pow2 + a;
    
    //@ assert an == ((((a)) * ((a)) * ((a))) + (((a)) * ((a))) + (a));
    return an;
}
