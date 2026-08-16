/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
unsigned int func(unsigned int a) {
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int result;
    
    a1 = a;
    //@ assert (1 <= (a1) && (a1) <= 10);
    
    //@ assert a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    
    a2 = a * a;
    a3 = a * a * a;
    result = a1 + a2 + a3;
    
    //@ assert result == ((a) + (a) * (a) + (a) * (a) * (a));
    return result;
}

int main() {
    return 0;
}
