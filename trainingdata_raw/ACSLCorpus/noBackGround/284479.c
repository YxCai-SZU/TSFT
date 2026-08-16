/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == 1 + 2 * n && \result <= 20001;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    
    //@ assert 1 <= n && n <= 10000;
    
    //@ assert 1 + 2 * n <= 20001;
    
    result = 1 + 2 * n;
    
    //@ assert result <= 20001;
    
    return result;
}

int main(void)
{
    return 0;
}
