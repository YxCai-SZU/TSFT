/*@
    requires ((n) <= 10);
    ensures ((\result) == (n) * 2 + 1);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int result;

    //@ assert ((n) * 2 + 1 <= 21);
    result = n * 2 + 1;
    return result;
}

int main()
{
    return 0;
}
