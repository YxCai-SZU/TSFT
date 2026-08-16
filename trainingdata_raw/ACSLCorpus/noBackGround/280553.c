/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
long func(long r)
{
    long pi_approx;
    long scaled_r;
    long circumference;
    long temp;
    long divisor;
    
    //@ assert (1 <= (r) && (r) <= 100);
    
    pi_approx = 314;
    scaled_r = r * 100;
    
    //@ assert scaled_r == ((r) * 100);
    
    circumference = 0;
    temp = 2 * pi_approx * scaled_r;
    divisor = 10000;
    
    //@ assert temp == 2 * 314 * r * 100;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant 0 <= circumference;
        loop invariant circumference * 10000 + temp == 2 * pi_approx * scaled_r;
        loop invariant 0 <= temp <= 2 * 314 * 100 * 100;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * 10000 + temp == 2 * pi_approx * scaled_r;
    
    return circumference;
}
