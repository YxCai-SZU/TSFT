/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x / 100 * 100 <= x);
    assigns \nothing;
*/
_Bool func(unsigned long long x) {
    unsigned long long quotient = 0;
    unsigned long long remainder = x;
    
    /*@
        loop invariant 0 <= quotient <= x / 100;
        loop invariant remainder == x - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100) {
        //@ assert remainder >= 100;
        quotient += 1;
        remainder -= 100;
        //@ assert remainder == x - quotient * 100;
    }
    
    //@ assert quotient == x / 100;
    //@ assert remainder == x % 100;
    
    return quotient * 100 <= x;
}

int main() {
    return 0;
}
