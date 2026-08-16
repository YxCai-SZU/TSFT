/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer div_500(integer x) = x / 500;
    logic integer mod_500(integer x) = x % 500;
    logic integer div_5_mod_500(integer x) = (x % 500) / 5;
    
    logic integer expected_result(integer x) = 
        div_500(x) * 1000 + div_5_mod_500(x) * 5;
*/

/*@
    requires valid_range(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
int func(int x)
{
    int x_500;
    int temp_x;
    int x_5;
    
    x_500 = 0;
    temp_x = x;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x <= x;
        loop invariant x_500 <= div_500(x);
        loop invariant temp_x == x - x_500 * 500;
        loop assigns x_500, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        x_500 += 1;
        temp_x -= 500;
    }
    
    x_5 = 0;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x <= x - x_500 * 500;
        loop invariant 0 <= x_5 <= div_5_mod_500(x);
        loop invariant temp_x == x - x_500 * 500 - x_5 * 5;
        loop assigns x_5, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        x_5 += 1;
        temp_x -= 5;
    }
    
    //@ assert x_5 <= div_5_mod_500(x);
    
    return x_500 * 1000 + x_5 * 5;
}

int main()
{
    return 0;
}
