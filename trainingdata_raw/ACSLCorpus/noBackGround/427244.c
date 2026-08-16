/*@
    requires a >= 0;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    int result;
    //@ assert a >= 0;
    result = a + a * a + a * a * a;
    //@ assert result == a + a * a + a * a * a;
    return result;
}

int main()
{
    return 0;
}
