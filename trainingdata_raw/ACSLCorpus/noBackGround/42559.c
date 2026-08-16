/*@
    requires x >= y;
    ensures \result == 0;
*/
int calc_example_6(int x, int y)
{
    //@ assert x >= y;
    return 0;
}

/*@
    requires x >= 0 && y >= 0;
    ensures \result == 0;
*/
int calc_example_7(int x, int y)
{
    //@ assert x * y >= 0;
    return 0;
}

/*@
    requires x >= 0 && y >= 0;
    ensures \result == 0;
*/
int calc_example_8(int x, int y)
{
    //@ assert x >= 0;
    //@ assert y >= 0;
    return 0;
}

int main()
{
    return 0;
}
