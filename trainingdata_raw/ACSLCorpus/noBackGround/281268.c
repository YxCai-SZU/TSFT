/*@
    requires x <= 100;
    ensures \result <= 50;
*/
int calc_example_2(int x)
{
    int result;
    //@ assert x <= 100;
    result = x / 2;
    //@ assert result <= 50;
    return result;
}

int main()
{
    return 0;
}
