/*@
    requires \valid(quotient) && \valid(remainder);
    requires (1 <= (r) <= 100);
    requires *quotient == 0 && *remainder == 2 * r * 314;
    assigns *quotient, *remainder;
    ensures *quotient == ((2 * (r) * 314) / 100);
    ensures *remainder == (2 * r * 314) - (*quotient * 100);
*/
void manual_division(int r, int* quotient, int* remainder) {
    int divisor = 100;
    int result = 2 * r * 314;
    
    //@ assert 2 * r * 314 <= 200 * 314;
    
    /*@
        loop invariant 0 <= *quotient <= result / divisor;
        loop invariant *remainder == result - (*quotient * divisor);
        loop invariant (1 <= (r) <= 100);
        loop invariant result == 2 * r * 314;
        loop invariant *quotient <= 628;
        loop assigns *quotient, *remainder;
        loop variant *remainder;
    */
    while (*remainder >= divisor) {
        (*quotient)++;
        *remainder -= divisor;
    }
}

/*@
    requires (1 <= (r) <= 100);
    assigns \nothing;
    ensures \result == ((2 * (r) * 314) / 100);
*/
int func(int r) {
    //@ assert 2 * r * 314 <= 200 * 314;
    
    int quotient = 0;
    int remainder = 2 * r * 314;
    
    manual_division(r, &quotient, &remainder);
    
    //@ assert quotient == ((2 * (r) * 314) / 100);
    return quotient;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
