/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_pi = 31415;
    logic integer scale_factor = 10000;
    
    logic integer expected_circumference(integer r) = (2 * scaled_pi * r) / scale_factor;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 31415 * r) / 10000;
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx = 31415;
    int scale = 10000;
    int circumference = 0;
    int temp = 2 * pi_approx * r;
    
    //@ assert valid_radius(r);
    
    /*@
        loop invariant 0 <= temp;
        loop invariant temp == 2 * pi_approx * r - circumference * scale;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        circumference += 1;
        temp -= scale;
    }
    
    //@ assert circumference * scale + temp == 2 * pi_approx * r;
    
    return circumference;
}

int main()
{
    return 0;
}
