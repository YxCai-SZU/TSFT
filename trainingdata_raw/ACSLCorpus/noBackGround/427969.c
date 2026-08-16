/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n / 2 >= n / 4);
    assigns \nothing;
*/
_Bool func(unsigned long n)
{
    // Variable declarations at scope top
    _Bool result;
    
    //@ assert 1 <= n && n <= 100;
    
    //@ assert n / 2 >= n / 4;
    
    result = (n / 2) >= (n / 4);
    return result;
}

int main(void)
{
    return 0;
}
