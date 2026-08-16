/*@
    requires 1 <= r && r <= 100;
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
long func(long r) {
    long pi;
    long scale;
    long circumference;
    long temp;
    long divisor;
    
    pi = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = scale;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 314159;
        loop invariant scale == 100000;
        loop invariant 2 * pi * r >= temp;
        loop invariant temp >= 0;
        loop invariant circumference * scale + temp == 2 * pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference == (2 * 314159 * r) / 100000;
    return circumference;
}
