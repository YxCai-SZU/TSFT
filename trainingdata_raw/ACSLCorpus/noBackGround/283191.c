/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
*/
int func(int n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= n * n && n * n <= 10000;
    return n * n;
}

int main()
{
    return 0;
}
