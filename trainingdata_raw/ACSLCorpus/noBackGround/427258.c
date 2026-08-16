/*@
    requires (0 <= (x) <= 65535);
    ensures \result == (x | 1);
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result;
    //@ assert (0 <= (x) <= 65535);
    result = x | 1;
    //@ assert result == (x | 1);
    return result;
}

/*@
    requires (0 <= (a) <= 65535) && (0 <= (b) <= 65535) && ((a) + (b) <= 65535);
    ensures \result == a + b;
    assigns \nothing;
*/
unsigned int add_no_carry(unsigned int a, unsigned int b)
{
    unsigned int result;
    //@ assert ((a) + (b) <= 65535);
    result = a + b;
    //@ assert result == a + b;
    return result;
}

int main()
{
    unsigned int tmp;
    tmp = func(10);
    return 0;
}
