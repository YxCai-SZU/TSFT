/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned int sa;
    unsigned int sc;
    unsigned int res;
    
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    
    //@ assert (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    
    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= ((a) * (b));
    //@ assert res >= ((c) * (d));
    
    return res;
}
