/*@
    requires 1 <= x <= 100;
    ensures \result == x * x;
    assigns \nothing;
*/
int func_1(int x)
{
    int result;
    //@ assert x * x <= x * x + 1;
    result = x * x;
    return result;
}

/*@
    requires 1 <= x <= 100;
    ensures \result == x * x + 1;
    assigns \nothing;
*/
int func_2(int x)
{
    int result;
    //@ assert x * x <= x * x + 1;
    result = x * x + 1;
    return result;
}

int main()
{
    return 0;
}
