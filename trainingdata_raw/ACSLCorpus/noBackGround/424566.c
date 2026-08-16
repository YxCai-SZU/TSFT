/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    ensures 1 <= \result <= 50;
*/
int func(int n)
{
    int count = 0;
    int temp_n = n;
    
    /*@
        loop invariant 0 <= count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop invariant temp_n >= 0;
        loop assigns count, temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        count += 1;
        temp_n -= 2;
    }
    
    if (temp_n == 1)
    {
        //@ assert temp_n == 1;
        count += 1;
    }
    
    //@ assert count == (((n) + 1) / 2);
    return count;
}
