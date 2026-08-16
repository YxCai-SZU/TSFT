/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
unsigned int f(unsigned int a) {
    // Variable declarations at scope top
    unsigned int res;
    
    //@ assert a >= 1 && a <= 10;
    //@ assert a + a * a + a * a * a >= 3;
    //@ assert a + a * a + a * a * a <= 1110;
    
    res = a + a * a + a * a * a;
    //@ assert res == ((a) + (a) * (a) + (a) * (a) * (a));
    
    return res;
}

int main() {
    return 0;
}
