/*@
    requires ((n) >= 0 && (n) <= 2147483647);
    ensures \result == n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert ((n) >= 0);
    //@ assert ((n) >= 0 && (n) <= 2147483647);
    return n;
}

int main()
{
    return 0;
}
