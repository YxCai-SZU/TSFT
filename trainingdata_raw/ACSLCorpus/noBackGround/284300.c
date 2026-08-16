/*@
requires x >= 10;
ensures \result == x + 5;
assigns \nothing;
*/
int add_five_to_x(int x)
{
    //@ assert x >= 10;
    int result = x + 5;
    //@ assert result == x + 5;
    return result;
}

/*@
requires x >= 5 && y >= 5;
ensures \result >= x - 2;
assigns \nothing;
*/
int complex_calculation(int x, int y)
{
    //@ assert x >= 5 && y >= 5;
    int intermediate = x + y;
    //@ assert intermediate >= x;
    int result = intermediate + 5;
    //@ assert result >= x - 2;
    return result;
}

int main()
{
    int a = 10;
    int b = 5;
    int res1 = add_five_to_x(a);
    int res2 = complex_calculation(a, b);
    return 0;
}
