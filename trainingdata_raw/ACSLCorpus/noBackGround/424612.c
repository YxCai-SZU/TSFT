/*@
    requires a == 1 && b == 2 && c == 3;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_arithmetic_layers(int a, int b, int c)
{
    // Variable declarations at scope top
    int result = 0;
    
    //@ assert a == 1 && b == 2;
    //@ assert a + b == 1 + b;
    //@ assert 1 + b == 1 + 2;
    //@ assert a + b == 3;
    
    //@ assert b == 2 && c == 3;
    //@ assert b + c == 2 + c;
    //@ assert 2 + c == 2 + 3;
    //@ assert b + c == 5;
    
    //@ assert (a + b) == (b + c) - 2;
    
    result = 1;
    return result;
}

int main()
{
    return 0;
}
