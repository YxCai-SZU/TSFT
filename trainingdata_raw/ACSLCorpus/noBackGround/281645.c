/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 3;
*/
int func(int r)
{
    int pi_approx;
    int precision_factor;
    int circumference;
    int divisor;
    int result;
    int temp;
    
    pi_approx = 3;
    precision_factor = 1000;
    circumference = 2 * r * pi_approx * precision_factor;
    divisor = precision_factor;
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3;
        loop invariant precision_factor == 1000;
        loop invariant circumference == 2 * r * pi_approx * precision_factor;
        loop invariant divisor == precision_factor;
        loop invariant result * precision_factor + temp == circumference;
        loop invariant 0 <= result;
        loop invariant 0 <= temp;
        loop assigns result, temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result == 2 * r * 3;
    return result;
}

int main()
{
    return 0;
}
