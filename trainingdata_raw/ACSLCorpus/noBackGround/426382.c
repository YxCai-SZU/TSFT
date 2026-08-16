/*@
    requires k >= 2;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_10(int n, int k)
{
    //@ assert k - 2 >= 0;
    return 0;
}

/*@
    requires k >= 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_20(int n, int k)
{
    //@ assert k + 2 >= 2;
    return 0;
}

int main()
{
    return 0;
}
