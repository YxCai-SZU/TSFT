/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures \result == 1 <==> n <= k;
    assigns \nothing;
*/
int func(int n, int k)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    return (n <= k) ? 1 : 0;
}

int main()
{
    return 0;
}
