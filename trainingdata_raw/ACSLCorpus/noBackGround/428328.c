/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
*/
int func(int n)
{
    int result;
    int i;
    int count;
    int n_copy;
    
    result = n * 800;
    i = 0;
    count = 0;
    n_copy = n;
    
    /*@
        loop invariant 0 <= count <= n / 15;
        loop invariant n_copy == n - 15 * count;
        loop invariant n_copy >= 0;
        loop assigns n_copy, count;
    */
    while (n_copy >= 15)
    {
        //@ assert n_copy >= 15;
        n_copy = n_copy - 15;
        count = count + 1;
        //@ assert n_copy == n - 15 * count;
    }
    
    //@ assert count == n / 15;
    result = result - count * 200;
    
    return result;
}
