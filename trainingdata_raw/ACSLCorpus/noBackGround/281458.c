/*@
    requires 0 <= n <= 100 && 0 <= m <= 100;
    ensures \result == n * m;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int res;
    
    //@ assert n * m <= 10000;
    
    res = n * m;
    return res;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
