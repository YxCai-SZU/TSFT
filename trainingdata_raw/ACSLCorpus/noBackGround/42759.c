/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 31415 * r / 10000;
*/
int func(int r) {
    int pi;
    int product;
    int divisor;
    int quotient;
    int remainder;
    
    pi = 31415;
    product = 2 * r * pi;
    divisor = 10000;
    quotient = 0;
    remainder = product;
    
    //@ assert 0 <= product <= 2 * 100 * 31415;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415;
        loop invariant divisor == 10000;
        loop invariant quotient * divisor + remainder == product;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient * divisor + remainder == product;
    //@ assert 0 <= remainder < divisor;
    //@ assert quotient == 2 * 31415 * r / 10000;
    
    return quotient;
}

int main() {
    return 0;
}
