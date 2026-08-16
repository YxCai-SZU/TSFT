/*@
    requires ((n) <= 8);
    ensures ((\result) <= 1000);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int x;
    unsigned int y;
    unsigned int result;

    x = 8;
    y = 8;

    //@ assert x <= 8;
    //@ assert y <= 8;
    //@ assert x * y <= 100;

    //@ assert n <= 8;
    //@ assert n * n <= 1000;

    //@ assert x * y <= 1000;
    //@ assert n * n <= 1000;

    result = n * n;
    //@ assert ((result) <= 1000);
    return result;
}

int main()
{
    return 0;
}
