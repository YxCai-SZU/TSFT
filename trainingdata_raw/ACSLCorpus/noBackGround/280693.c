/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
*/
_Bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    unsigned int i;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant (1 <= (n) <= 100 && 0 <= (m) <= (n));
        loop assigns i;
    */
    while (i < 10)
    {
        //@ assert 0 <= i * i <= 10000;
        i++;
    }
    
    //@ assert n == m || n != m;
    return n == m;
}
