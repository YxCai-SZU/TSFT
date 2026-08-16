/*@
    requires (1 <= (n) <= 100000);
    ensures \result >= -1;
    ensures \result >= 0 ==> \result <= ((n) * 800 - 200 * ((n) / 15));
    assigns \nothing;
*/
int func(int n)
{
    int res = -1;
    int i = 1;
    
    //@ ghost int original_n = n;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant res >= -1;
        loop invariant res == -1 || (res >= 0 && res <= ((original_n) * 800 - 200 * ((original_n) / 15)));
        loop assigns i, res;
        loop variant n - i;
    */
    while (i <= n)
    {
        int term = 3 * (i / 15) + (i % 15);
        
        //@ assert term == 3 * (i / 15) + (i % 15);
        
        if (term >= n)
        {
            res = term;
            break;
        }
        
        i = i + 1;
    }
    
    //@ assert res >= -1;
    
    if (res >= 0)
    {
        //@ assert res <= ((original_n) * 800 - 200 * ((original_n) / 15));
    }
    
    return res;
}

int main()
{
    return 0;
}
