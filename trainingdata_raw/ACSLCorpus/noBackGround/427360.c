/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 3142) / 1000);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int pi;
    int two;
    int scale;
    int circumference;
    int temp_r;
    int temp_pi;
    int temp_two;
    int product;
    int i;
    
    // Initialization
    pi = 3142;
    two = 2;
    scale = 1000;
    circumference = 0;
    temp_r = r;
    temp_pi = pi;
    temp_two = two;
    product = 0;
    i = 0;
    
    // First loop: calculate r * 2 * pi
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= i <= r;
        loop invariant product == i * 2 * pi;
        loop invariant temp_r == r;
        loop invariant temp_pi == pi;
        loop invariant temp_two == two;
        loop assigns i, product;
        loop variant r - i;
    */
    while (i < temp_r)
    {
        //@ assert product + (temp_two * temp_pi) == (i + 1) * 2 * pi;
        product += temp_two * temp_pi;
        i += 1;
    }
    
    //@ assert product == r * 2 * pi;
    
    // Second loop: divide by scale
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= product <= r * 2 * pi;
        loop invariant circumference * scale + product == r * 2 * pi;
        loop invariant temp_r == r;
        loop invariant temp_pi == pi;
        loop invariant temp_two == two;
        loop invariant scale == 1000;
        loop assigns circumference, product;
        loop variant product;
    */
    while (product >= scale)
    {
        //@ assert (circumference + 1) * scale + (product - scale) == r * 2 * pi;
        circumference += 1;
        product -= scale;
    }
    
    //@ assert circumference * scale <= r * 2 * pi;
    //@ assert circumference * scale + product == r * 2 * pi;
    //@ assert product < scale;
    //@ assert circumference == ((2 * (r) * 3142) / 1000);
    
    return circumference;
}

int main()
{
    return 0;
}
