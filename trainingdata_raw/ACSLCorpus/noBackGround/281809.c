/*@
    requires 1 <= a && a <= 10;
    ensures \result == 2 * a && \result <= 50;
    assigns \nothing;
*/
int example_1(int a)
{
    int result;

    //@ assert 1 <= a && a <= 10;
    result = 2 * a;
    //@ assert result <= 50;
    return result;
}

int main()
{
    int a;
    int result;

    a = 5;
    result = example_1(a);
    return 0;
}
