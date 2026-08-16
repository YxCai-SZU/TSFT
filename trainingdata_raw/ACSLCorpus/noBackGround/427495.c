/*@
requires 0 <= a && a <= 100;
requires 1 <= b && b <= 100;
requires 0 <= c && c <= 100;
requires a + b + c < 200;
assigns \nothing;
ensures a + b + c < 300;
*/
void example_inequality(int a, int b, int c)
{
    //@ assert a + b + c < 200;
    //@ assert a + b + c < 300;
}

int main()
{
    int a = 50;
    int b = 50;
    int c = 50;
    
    //@ assert a + b + c == 150;
    example_inequality(a, b, c);
    
    return 0;
}
