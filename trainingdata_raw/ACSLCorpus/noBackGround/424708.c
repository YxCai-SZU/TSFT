/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    unsigned int c;
    int res;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((1 <= ((a)) && ((a)) <= 10000) && (1 <= ((b)) && ((b)) <= 10000) ==> (a) * (b) <= 100000000);
    
    c = a * b;
    res = (c % 2 != 0);
    
    return res;
}
