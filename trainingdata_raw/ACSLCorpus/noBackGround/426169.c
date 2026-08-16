/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= 100);
    ensures \result == 0 || \result == 1;
*/
int func(int n, int k)
{
    int remainder;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (k) && (k) <= 100);
    remainder = n;

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 100 &&
        1 <= ((k)) && ((k)) <= 100) &&
        0 <= (remainder) && (remainder) <= (n));
        loop assigns remainder;
    */
    while (remainder >= k)
    {
        //@ assert remainder >= k && remainder <= n;
        remainder -= k;
        //@ assert remainder >= 0 && remainder <= n - k;
    }

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 100 &&
        1 <= ((k)) && ((k)) <= 100) &&
        0 <= (remainder) && (remainder) <= (n));
        loop assigns remainder;
    */
    while (remainder >= 1)
    {
        //@ assert remainder >= 1 && remainder <= n;
        remainder -= 1;
        //@ assert remainder >= 0 && remainder <= n - 1;
    }

    //@ assert remainder >= 0 && remainder <= n;
    if (remainder == 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = 1;
        //@ assert result == 1;
    }
    
    return result;
}
