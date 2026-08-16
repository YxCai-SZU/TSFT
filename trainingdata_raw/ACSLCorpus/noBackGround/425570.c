/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * 3141592 / 1000000);
    assigns \nothing;
*/
long func(long r) {
    long result;
    long temp;
    long divisor;
    long count;
    long pi;
    
    //@ assert (1 <= (r) && (r) <= 100);
    pi = 3141592;
    divisor = 1000000;
    result = 0;
    temp = 2 * r * pi;
    count = 0;
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (pi) == 3141592 &&
        (divisor) == 1000000 &&
        (temp) >= 0 &&
        (count) * (divisor) + (temp) == 2 * (r) * (pi));
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        count += 1;
        //@ assert count * divisor + temp == 2 * r * pi;
    }
    result = count;
    
    //@ assert result == (2 * (r) * 3141592 / 1000000);
    return result;
}
