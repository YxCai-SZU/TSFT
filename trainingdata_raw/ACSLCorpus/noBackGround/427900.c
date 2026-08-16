/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 1 <= n && n <= 100;
    ensures \result == (a * b) % n;
    assigns \nothing;
*/
int func(int a, int b, int n)
{
    int res;
    
    //@ assert 0 <= a * b && a * b <= 100 * 100;
    
    res = (a * b) % n;
    return res;
}

int main()
{
    return 0;
}
