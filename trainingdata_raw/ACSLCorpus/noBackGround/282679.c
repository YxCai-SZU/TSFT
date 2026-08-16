/*@
    requires 1 <= n <= 100;
    ensures \result == n * n * 3;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    //@ assert n * n * 3 <= 30000;
    
    return n * n * 3;
}

int main()
{
    return 0;
}
