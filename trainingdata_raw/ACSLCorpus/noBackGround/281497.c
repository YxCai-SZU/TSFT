/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b) {
    unsigned int product;
    int is_even;
    
    //@ assert a * b <= 100000000;
    
    product = a * b;
    is_even = (product % 2 == 0);
    
    //@ assert is_even == (a * b % 2 == 0);
    
    return is_even;
}

int main() {
    return 0;
}
