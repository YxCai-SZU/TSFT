/*@
requires 0 <= n && 0 <= m && 0 <= i && i <= n + m;
ensures 0 <= n + m - \old(i) <= n + m;
*/
void func(int n, int m, int i)
{
    //@ assert 0 <= n + m - i;
    //@ assert n + m - i <= n + m;
}

int main()
{
    return 0;
}
