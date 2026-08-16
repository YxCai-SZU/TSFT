/*@
    requires ((x) > 0);
    ensures \result == 1;
*/
int calc_example_3(int x)
{
    //@ assert x * 2 <= x * 4;
    return 1;
}

/*@
    requires ((x) > 0);
    ensures \result == 1;
*/
int square_difference(int x)
{
    //@ assert (x + 1) * (x + 1) - x * x == 2 * x + 1;
    return 1;
}

int main()
{
    return 0;
}
