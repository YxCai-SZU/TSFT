/*@
    requires ((x) >= 0) && ((y) >= 0);
    ensures \result >= 0;
    assigns \nothing;
*/
int calc_example_3(int x, int y)
{
    //@ assert ((x) >= 0) && ((y) >= 0);
    //@ assert x * x + y * y >= 0;
    return x * x + y * y;
}

/*@
    requires ((x) > 0) && ((y) > 0);
    ensures \result > 0;
    assigns \nothing;
*/
int calc_example_4(int x, int y)
{
    //@ assert ((x) > 0) && ((y) > 0);
    //@ assert x * x + y * y > 0;
    return x * x + y * y;
}

int main()
{
    return 0;
}
