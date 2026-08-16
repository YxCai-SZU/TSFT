/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
long func(long x) {
    long temp;
    long result;
    
    temp = 1;
    result = 0;
    
    /*@
        loop invariant (1 <= (x) <= 1000000000 &&
        1 <= (temp) &&
        (result) >= 0 &&
        (result) <= (temp) - 1 &&
        (temp) <= 2 * (x));
        loop assigns temp, result;
        loop variant ((x) - (temp) / 2);
    */
    while (temp <= x) {
        //@ assert temp <= x;
        result += 1;
        temp *= 2;
    }
    
    return result;
}
