/*@
    requires -1000 <= n <= 1000;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert -1000 <= n <= 1000;
    //@ assert -1000000 <= n * n <= 1000000;
    //@ assert -1000000000 <= n * n * n <= 1000000000;
    
    int result;
    result = n * n * n;
    
    //@ assert result == n * n * n;
    return result;
}

int main()
{
    return 0;
}
