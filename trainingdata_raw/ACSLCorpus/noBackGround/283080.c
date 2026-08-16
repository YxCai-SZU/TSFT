/*@
    requires 1 <= l <= 1000;
    ensures \result == (l / 3) * (l / 3) * (l / 3);
    assigns \nothing;
*/
long func(long l)
{
    long l_div_3;
    long temp_l;
    long count;
    long l_div_3_squared;
    long res;
    
    l_div_3 = 0;
    temp_l = l;
    count = 0;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant temp_l >= 0;
        loop invariant count >= 0;
        loop invariant l == temp_l + 3 * count;
        loop assigns temp_l, count;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        count += 1;
    }
    l_div_3 = count;
    
    //@ assert l_div_3 >= 0 && l_div_3 <= 333;
    //@ assert l_div_3 >= 0;
    
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    l_div_3_squared = l_div_3 * l_div_3;
    
    //@ assert l_div_3_squared * l_div_3 <= 333 * 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_div_3 >= 0;
    
    res = l_div_3 * l_div_3 * l_div_3;
    
    //@ assert res == (l / 3) * (l / 3) * (l / 3);
    return res;
}
