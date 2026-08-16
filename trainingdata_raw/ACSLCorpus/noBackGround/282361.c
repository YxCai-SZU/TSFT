/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures 1 <= \result && \result <= 10000 * 10000;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int sa;
    unsigned int sc;
    unsigned int res;
    
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    //@ assert (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa == ((a) * (b));
    //@ assert sc == ((c) * (d));
    
    //@ assert sa >= 1;
    //@ assert sc >= 1;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert 1 <= res && res <= 10000 * 10000;
    
    return res;
}
