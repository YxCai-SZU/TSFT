/*@
    requires 0 <= x && x <= 100;
    requires 0 <= y && y <= 100;
    ensures \result <= 10000;
    assigns \nothing;
*/
int example_4(int x, int y)
{
    int result;
    
    //@ assert (0 <= (x) && (x) <= 100 &&         0 <= (y) && (y) <= 100);
    
    result = x * y;
    
    //@ assert result <= 10000;
    
    return result;
}

int main()
{
    int a;
    int b;
    int product;
    
    a = 50;
    b = 50;
    
    product = example_4(a, b);
    
    return 0;
}
