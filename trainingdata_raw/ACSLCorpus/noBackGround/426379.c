/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * (n + 1) / 2;
*/
int func(int n)
{
    int sum;
    int i;
    
    sum = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant sum == (((i) - 1) * (i) / 2);
        loop invariant i > 0;
        loop invariant i <= n + 1;
        loop assigns sum, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        //@ assert 0 <= i * (i + 1) <= 100 * (100 + 1);
        
        //@ assert sum + i >= 0;
        
        //@ assert sum + i == i * (i + 1) / 2;
        
        sum = sum + i;
        i = i + 1;
    }
    
    //@ assert sum == n * (n + 1) / 2;
    
    return sum;
}

int main()
{
    return 0;
}
