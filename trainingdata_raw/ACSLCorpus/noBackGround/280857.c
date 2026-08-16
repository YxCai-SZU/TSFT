/*@
    requires a == b;
    ensures \result == b - 0;
    assigns \nothing;
*/
int calc_example_7(int a, int b)
{
    //@ assert ((a) + (0) == (a) + (0));
    //@ assert a == a - 0;
    //@ assert a - 0 == b - 0;
    return a;
}

int main()
{
    return 0;
}
