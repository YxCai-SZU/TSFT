/*@
    requires (1 <= (a) <= 10000);
    ensures \result == (((a) + 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int b;
    unsigned int result;

    //@ assert (1 <= (a) <= 10000);
    b = a + 1;
    result = b / 2;
    //@ assert result == (((a) + 1) / 2);
    return result;
}

/*@
    requires (1 <= (a) <= 10000);
    ensures \result == (((a) + 1) / 2);
    assigns \nothing;
*/
unsigned int func2(unsigned int a)
{
    unsigned int b;
    unsigned int result;

    //@ assert (1 <= (a) <= 10000);
    b = a + 1;
    result = b / 2;
    //@ assert result == (((a) + 1) / 2);
    return result;
}

int main()
{
    return 0;
}
