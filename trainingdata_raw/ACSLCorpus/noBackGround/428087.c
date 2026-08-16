/*@
    requires 1 <= n <= 10;
    ensures \result == n + n * n + n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    int res;
    //@ assert 1 <= n && n <= 10;
    //@ assert 1 <= n * n && n * n <= 100;
    //@ assert 1 <= n * n * n && n * n * n <= 1000;
    res = n + n * n + n * n * n;
    return res;
}

int main()
{
    int n;
    int result;
    n = 5;
    result = func(n);
    //@ assert result == 155;
    return 0;
}
