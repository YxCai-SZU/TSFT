/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert 1 <= n <= 100 && 1 <= m <= 100;
    //@ assert 0 <= n - 1 <= 99;
    //@ assert 0 <= m - 1 <= 99;
    //@ assert 0 <= (n - 1) * (m - 1) <= 9801;
    
    return (n - 1) * (m - 1);
}
