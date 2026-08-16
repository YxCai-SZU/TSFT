/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * 31415 * (r)) / 10000);
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int circumference;
    int temp;
    int divisor;
    
    pi_approx = 31415;
    circumference = 0;
    temp = 2 * pi_approx * r;
    divisor = 10000;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant divisor == 10000;
        loop invariant temp >= 0;
        loop invariant circumference * 10000 + temp == 2 * pi_approx * r;
        loop invariant circumference * 10000 + temp <= 2 * 31415 * 100;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * 10000 + temp == 2 * pi_approx * r;
    //@ assert temp < 10000;
    //@ assert circumference * 10000 + temp <= 2 * 31415 * 100;
    
    return circumference;
}

int main()
{
    return 0;
}
