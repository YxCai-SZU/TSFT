/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
unsigned int func(unsigned int a) {
    unsigned int result;
    
    //@ assert 1 <= a && a <= 10;
    //@ assert a + a * a + a * a * a <= 10 + 10 * 10 + 10 * 10 * 10;
    
    result = a + a * a + a * a * a;
    return result;
}

int main() {
    return 0;
}
