/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0 && \result <= n;
*/
int func(int n)
{
    int i;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    i = 1;
    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 10000) && 1 <= (i));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert i < n;
        i = i + 1;
        //@ assert i <= n;
    }
    
    result = 0;
    //@ assert result >= 0 && result <= n;
    return result;
}

int main()
{
    return 0;
}
