/*@
requires a == 5 && b == 2 * a;
ensures \result == a;
assigns \nothing;
*/
int calc_example_3_impl(int a, int b)
{
    //@ assert b - 5 == 2 * a - 5;
    //@ assert 2 * a - 5 == 2 * 5 - 5;
    //@ assert 2 * 5 - 5 == 5;
    //@ assert b - 5 == a;
    return b - 5;
}

/*@
requires 1 <= x && x <= 5;
ensures \result <= 15;
assigns \nothing;
*/
int calc_example_4_impl(int x)
{
    //@ assert (1 <= (x) && (x) <= 5);
    //@ assert x * 3 <= 15;
    return x * 3;
}

int main()
{
    int a;
    int b;
    int x;
    int result1;
    int result2;
    
    a = 5;
    b = 2 * a;
    result1 = calc_example_3_impl(a, b);
    
    x = 3;
    result2 = calc_example_4_impl(x);
    
    return 0;
}
