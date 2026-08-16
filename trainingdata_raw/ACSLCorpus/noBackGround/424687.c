/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n * 800 - (n / 15 * 200);
*/
int func(int n)
{
    int result;
    int i;
    int count;
    int n_temp;
    
    result = n * 800;
    i = 0;
    count = 0;
    n_temp = n;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= n_temp && n_temp <= n;
        loop invariant n_temp == n - 15 * count;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant count == (n - n_temp) / 15;
        loop assigns n_temp, count;
    */
    while (n_temp >= 15)
    {
        //@ assert n_temp >= 15;
        n_temp = n_temp - 15;
        count = count + 1;
        //@ assert n_temp == n - 15 * count;
    }
    
    //@ assert count == n / 15;
    result = result - count * 200;
    
    return result;
}
