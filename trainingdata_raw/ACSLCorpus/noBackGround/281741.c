/*@
    requires ((n) < 10000);
    ensures \result == ((n) + 1);
    assigns \nothing;
*/
unsigned int add_one(unsigned int n)
{
    unsigned int res;
    //@ assert ((n) < 10000);
    res = n + 1;
    //@ assert res == ((n) + 1);
    return res;
}

/*@
    requires ((n) < 10000);
    ensures \result == (2 * (n));
    assigns \nothing;
*/
unsigned int double_it(unsigned int n)
{
    unsigned int res;
    //@ assert ((n) < 10000);
    res = 2 * n;
    //@ assert res == (2 * (n));
    return res;
}

int main()
{
    return 0;
}
