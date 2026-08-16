/*@
requires (1 <= (x) && (x) <= 5 && 1 <= (y) && (y) <= 5);
ensures \result >= 2 && \result <= 10;
*/
int check_bounds(int x, int y)
{
    //@ assert (1 <= (x) && (x) <= 5 && 1 <= (y) && (y) <= 5);
    //@ assert x + y >= 2;
    //@ assert x + y <= 10;
    return x + y;
}

int main()
{
    int a;
    int b;
    int c;
    
    // Test calc_example_8 logic
    a = 5;
    b = 5;
    c = 5;
    //@ assert a == b && b == c;
    //@ assert a == c;
    
    // Test check_bounds
    int x = 3;
    int y = 4;
    int result = check_bounds(x, y);
    
    return 0;
}
