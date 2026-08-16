/*@
    requires ((x) <= 5 && (x) >= 3);
    ensures \result == 0;
    assigns \nothing;
*/
int func_example_1(int x)
{
    //@ assert x <= 5;
    return 0;
}

int main()
{
    return 0;
}
