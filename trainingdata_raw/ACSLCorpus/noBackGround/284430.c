/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    ensures \result == ((a * b) % 2 != 0);
*/
int func(unsigned int a, unsigned int b) {
    unsigned int c;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b) <= 10000 * 10000);
    
    c = a * b;
    
    //@ assert c == a * b;
    //@ assert \exists integer r; c % 2 == r;
    
    return c % 2 != 0;
}
