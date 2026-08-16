/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result <= 1000;
    ensures \result == n * m;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    //@ assert n * m <= 400;
    //@ assert n * m >= 1;
    
    unsigned int result = n * m;
    //@ assert result == n * m;
    return result;
}

int main()
{
    return 0;
}
