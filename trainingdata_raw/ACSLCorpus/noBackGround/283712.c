/*@
    requires 1 <= n <= 100;
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int func(int n)
{
    int res;
    int count;
    int temp_n;
    
    res = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert (0 <= (count) && (count) <= (n) / 15);
        temp_n = temp_n - 15;
        count = count + 1;
        //@ assert ((temp_n) >= 0 && (temp_n) == (n) - 15 * (count));
    }
    
    //@ assert count == n / 15;
    res = res - count * 200;
    return res;
}
