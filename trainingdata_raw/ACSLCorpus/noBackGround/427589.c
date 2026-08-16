/*@
    requires (1 <= (x) <= 10000);
    ensures \result == (1000 * (((x)) / 500) + 5 * (((((x)) % 500)) / 5));
    assigns \nothing;
*/
int func(int x)
{
    int result = 0;
    int temp_x = x;
    int quotient_500 = 0;
    int quotient_5 = 0;
    
    //@ assert (1 <= (x) <= 10000);
    
    /*@
        loop invariant 0 <= quotient_500;
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x == x - 500 * quotient_500;
        loop assigns temp_x, quotient_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        quotient_500 += 1;
        //@ assert temp_x == x - 500 * quotient_500;
    }
    
    result += 1000 * quotient_500;
    //@ assert result == 1000 * quotient_500;
    
    /*@
        loop invariant 0 <= quotient_5;
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x == x - 500 * quotient_500 - 5 * quotient_5;
        loop assigns temp_x, quotient_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        quotient_5 += 1;
        //@ assert temp_x == x - 500 * quotient_500 - 5 * quotient_5;
    }
    
    result += 5 * quotient_5;
    //@ assert result == 1000 * quotient_500 + 5 * quotient_5;
    
    return result;
}

int main()
{
    return 0;
}
