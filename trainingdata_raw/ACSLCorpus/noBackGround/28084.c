/*@
    requires 1 <= r && r <= 100;
    ensures \result == 2 * 3141592 * r / 1000000;
*/
long func(long r)
{
    long pi;
    long ans;
    long temp;
    long count;
    
    pi = 3141592;
    ans = 0;
    temp = 2 * pi * r;
    count = 0;
    
    //@ assert ((1 <= ((r)) && ((r)) <= 100) &&         (((pi)) == 3141592) &&         0 <= (temp) && (temp) <= (2 * ((pi)) * ((r))) &&         (temp) + 1000000 * (count) == (2 * ((pi)) * ((r))) &&         (count) >= 0);
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (((pi)) == 3141592) &&
        0 <= (temp) && (temp) <= (2 * ((pi)) * ((r))) &&
        (temp) + 1000000 * (count) == (2 * ((pi)) * ((r))) &&
        (count) >= 0);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000000) {
        //@ assert temp >= 1000000;
        temp -= 1000000;
        count += 1;
        //@ assert ((1 <= ((r)) && ((r)) <= 100) &&         (((pi)) == 3141592) &&         0 <= (temp) && (temp) <= (2 * ((pi)) * ((r))) &&         (temp) + 1000000 * (count) == (2 * ((pi)) * ((r))) &&         (count) >= 0);
    }
    
    ans = count;
    //@ assert ans == 2 * 3141592 * r / 1000000;
    return ans;
}
