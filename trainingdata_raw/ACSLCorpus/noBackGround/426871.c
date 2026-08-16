/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int res;
    
    //@ assert a > 0 && a <= 100;
    //@ assert b > 0 && b <= 100;
    
    //@ assert a * b <= 10000;
    
    res = a * b;
    return res;
}
