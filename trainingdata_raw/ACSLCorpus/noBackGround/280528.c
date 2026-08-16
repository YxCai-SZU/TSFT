/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((((a) * 10) / 2) >= b);
*/
int func(long long a, long long b) {
    long long temp;
    long long count;
    long long remainder;
    
    temp = 0;
    count = 0;
    remainder = a * 10;
    
    /*@
        loop invariant ((remainder) >= 0);
        loop invariant ((remainder) == (a) * 10 - 2 * (count));
        loop invariant ((count) >= 0 && (count) <= ((a) * 10) / 2);
        loop assigns remainder, count;
    */
    while (remainder >= 2) {
        //@ assert remainder >= 2;
        remainder -= 2;
        count += 1;
    }
    
    temp = count;
    
    //@ assert temp == (((a) * 10) / 2);
    return temp >= b;
}
