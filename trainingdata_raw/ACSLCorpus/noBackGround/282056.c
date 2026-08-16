/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
long func(long r) {
    long pi = 314;
    long ans = 0;
    long temp = 2 * r * pi;
    long quotient = 0;
    long remainder = temp;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant quotient >= 0;
        loop invariant 0 <= remainder <= 2 * r * pi;
        loop invariant quotient * 100 + remainder == temp;
        loop assigns quotient, remainder;
    */
    while (remainder >= 100) {
        //@ assert remainder >= 100;
        quotient += 1;
        remainder -= 100;
        //@ assert remainder >= 0;
    }
    
    ans = quotient;
    
    //@ assert quotient * 100 + remainder == 2 * r * pi;
    //@ assert remainder < 100;
    //@ assert quotient == 2 * r * 314 / 100;
    
    return ans;
}
