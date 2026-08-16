/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int func(int n)
{
    int n_15;
    int temp_n;
    int r;
    
    n_15 = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant n_15 >= 0;
        loop invariant n_15 <= n / 15;
        loop invariant temp_n == n - n_15 * 15;
        loop assigns n_15, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        n_15 = n_15 + 1;
        temp_n = temp_n - 15;
    }
    
    //@ assert n_15 == n / 15;
    r = n * 800 - n_15 * 200;
    
    return r;
}

int main()
{
    return 0;
}
