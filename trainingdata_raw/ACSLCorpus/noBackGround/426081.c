/*@
    requires x <= y;
    requires y <= 10;
    ensures \result == 0;
    assigns \nothing;
*/
int property_preservation_impl(int x, int y)
{
    //@ assert x <= y;
    //@ assert y <= 10;
    //@ assert x <= 10;
    return 0;
}

/*@
    requires 2 <= x;
    requires x <= 5;
    ensures \result == 0;
    assigns \nothing;
*/
int compound_inequality_impl(int x)
{
    //@ assert 2 <= x;
    //@ assert x <= 5;
    //@ assert x + 2 <= 7;
    return 0;
}

/*@
    requires 2 <= x;
    requires x <= 5;
    requires 1 <= y;
    requires y <= 3;
    ensures \result == 0;
    assigns \nothing;
*/
int more_complex_calc_impl(int x, int y)
{
    //@ assert 2 <= x;
    //@ assert x <= 5;
    //@ assert 1 <= y;
    //@ assert y <= 3;
    //@ assert x + y <= 8;
    return 0;
}

int main()
{
    int x;
    int y;
    
    x = 3;
    y = 7;
    property_preservation_impl(x, y);
    
    x = 4;
    compound_inequality_impl(x);
    
    x = 3;
    y = 2;
    more_complex_calc_impl(x, y);
    
    return 0;
}
