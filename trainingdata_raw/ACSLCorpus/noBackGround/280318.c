/*@
    requires (1 <= (n) <= 100 && 1 <= (x) <= 10000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int x)
{
    int count = 0;
    int sum = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant sum == 100 * i;
        loop invariant count <= n;
        loop invariant sum <= 100 * n;
        loop assigns count, sum, i;
        loop variant n - i;
    */
    while (i < n)
    {
        sum += 100;
        
        if (sum <= x)
        {
            count += 1;
        }
        else
        {
            break;
        }
        
        i += 1;
        
        //@ assert sum == 100 * i;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
