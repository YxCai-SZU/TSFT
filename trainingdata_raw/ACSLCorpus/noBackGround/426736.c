/*@
requires n == 10;
ensures n * 2 * 2 == 40;
*/
void test_calc_example_5(int n)
{
    //@ assert n == 10;
    //@ assert n * 2 == 20;
    //@ assert n * 2 * 2 == 40;
}

int main()
{
    return 0;
}
