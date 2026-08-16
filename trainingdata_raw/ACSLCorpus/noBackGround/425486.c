/*@
    requires (1 <= (n) && 1 <= (k) && (n) <= 100000 && (k) <= (n));
    ensures \result >= 0 && \result <= n;
    ensures \result == n - k + 1;
*/
int func(int n, int k)
{
    int result = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        (result) == ((i) < (k) - 1 ? 0 : (i) - ((k) - 1)) &&
        (1 <= ((n)) && 1 <= ((k)) && ((n)) <= 100000 && ((k)) <= ((n))) &&
        (result) <= (i));
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n)
    {
        if (i >= k - 1)
        {
            result += 1;
        }
        i += 1;
    }
    
    //@ assert result == n - k + 1;
    return result;
}
