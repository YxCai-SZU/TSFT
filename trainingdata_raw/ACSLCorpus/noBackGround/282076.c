/*@
    requires 1 <= a && a <= 10;
    ensures \result == a * a * a && \result <= 10 * 10 * 10;
    assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 10 * 10;
    //@ assert a * a * a <= 10 * 10 * 10;
    return a * a * a;
}

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a * a * a && \result <= 10 * 10 * 10;
    assigns \nothing;
*/
int func2(int a)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert a * a <= 10 * 10;
    //@ assert a * a * a <= 10 * 10 * 10;
    //@ assert 1 <= a && a <= 10;
    return a * a * a;
}

int main()
{
    return 0;
}
