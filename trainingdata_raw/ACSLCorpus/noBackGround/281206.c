/*@
    requires -40 <= n <= 40;
    ensures \result == (n >= 30);
*/
int func(int n)
{
    int result;
    
    if (n >= 30)
    {
        //@ assert n >= 30;
        result = 1;
    }
    else
    {
        //@ assert n < 30;
        result = 0;
    }
    
    return result;
}

int main()
{
    return 0;
}
