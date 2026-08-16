/*@
requires ((x) >= 0);
ensures 2 * (x + 2) <= 2 * x + 20;
*/
void calc_example_1(int x)
{
    //@ assert 2 * (x + 2) == 2 * x + 4;
    //@ assert 2 * x + 4 <= 2 * x + 20;
}

/*@
requires ((x) >= 0);
ensures 2 * x <= 2 * (x + 10);
*/
void calc_example_2(int x)
{
    //@ assert 2 * x <= 2 * x + 20;
    //@ assert 2 * x + 20 == 2 * (x + 10);
}

/*@
requires ((x) >= 0);
requires 2 * (x + 2) <= 2 * x + 20;
*/
void test_calc_example_1(int x)
{
    //@ assert 2 * (x + 2) <= 2 * x + 20;
}

/*@
requires ((x) >= 0);
requires 2 * x <= 2 * (x + 10);
*/
void test_calc_example_2(int x)
{
    //@ assert 2 * x <= 2 * (x + 10);
}

int main()
{
    return 0;
}
