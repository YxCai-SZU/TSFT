/*@
requires x >= 0;
ensures 3 * x - x == 2 * x;
*/
void calc_example_3(int x)
{
    //@ assert x >= 0;
    //@ assert 3 * x - x == 2 * x;
}

int main()
{
    return 0;
}
