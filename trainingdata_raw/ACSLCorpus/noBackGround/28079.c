/*@
    requires 1 <= x <= 3;
    ensures \result >= 1;
    assigns \nothing;
*/
int calc_example_8(int x)
{
    int i;
    int result;
    
    i = x;
    //@ assert 1 <= i && i <= 3;
    
    //@ assert ((1) * ((1) + 2)) >= 1;
    //@ assert ((2) * ((2) + 2)) >= 1;
    //@ assert ((3) * ((3) + 2)) >= 1;
    
    result = x * (x + 2);
    //@ assert result >= 1;
    
    return result;
}

int main()
{
    return 0;
}
