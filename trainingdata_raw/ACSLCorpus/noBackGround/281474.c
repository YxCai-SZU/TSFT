/*@
    requires (1 <= (n) && (n) <= 10);
    ensures \result == n * 1000;
    assigns \nothing;
*/
int func(int n)
{
    int ans = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == i * 1000;
        loop invariant (1 <= (n) && (n) <= 10);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n)
    {
        int add = 0;
        int j = 0;
        
        /*@
            loop invariant 0 <= j <= 1000;
            loop invariant add == j;
            loop invariant (1 <= (n) && (n) <= 10);
            loop assigns add, j;
            loop variant 1000 - j;
        */
        while (j < 1000)
        {
            //@ assert add == j;
            add += 1;
            j += 1;
        }
        
        //@ assert add == 1000;
        ans += add;
        i += 1;
    }
    
    //@ assert ans == n * 1000;
    return ans;
}

int main()
{
    return 0;
}
