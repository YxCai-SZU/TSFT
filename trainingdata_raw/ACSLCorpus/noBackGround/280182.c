/*@
    requires n <= 10000 && n >= 1;
    ensures \result == 0;
    assigns \nothing;
*/
int proof_example_1(int n)
{
    //@ assert 0 <= n + 10000;
    return 0;
}

/*@
    requires n <= 10000 && n >= 1;
    ensures \result == 0;
    assigns \nothing;
*/
int proof_example_2(int n)
{
    //@ assert 0 <= n + 20000;
    return 0;
}

int main()
{
    return 0;
}
