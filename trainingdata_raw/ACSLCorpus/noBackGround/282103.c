/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == ((((n) / 10) % 10) == ((n) % 10));
    assigns \nothing;
*/
int func(unsigned long n) {
    unsigned long n_unsigned;
    unsigned long d1;
    unsigned long d2;
    int result;
    
    n_unsigned = n;
    
    //@ assert n_unsigned / 10 < 100;
    //@ assert n_unsigned < 1000;
    
    d1 = n_unsigned / 10 % 10;
    d2 = n_unsigned % 10;
    
    //@ assert d1 == (((n) / 10) % 10);
    //@ assert d2 == ((n) % 10);
    
    result = (d1 == d2);
    return result;
}
