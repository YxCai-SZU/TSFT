/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
int func(unsigned long long a, unsigned long long b) {
    unsigned long long product;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    
    return product % 2 != 0;
}
