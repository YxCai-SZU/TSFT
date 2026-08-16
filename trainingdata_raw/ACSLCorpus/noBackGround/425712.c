/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0;
    ensures \result == ((n) / 3) || \result == ((n) / 3) + 1;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    int remainder;

    result = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant n == temp_n + 3 * count;
        loop invariant count >= 0;
        loop invariant count <= ((n) / 3);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        count += 1;
    }

    //@ assert temp_n >= 0 && temp_n < 3;
    
    if (temp_n >= 0)
    {
        remainder = temp_n;
    }
    else
    {
        remainder = temp_n + 3;
    }

    //@ assert remainder >= 0 && remainder < 3;
    
    if (remainder == 0)
    {
        result = count;
    }
    else
    {
        result = count + 1;
    }

    //@ assert result >= 0;
    //@ assert result == ((n) / 3) || result == ((n) / 3) + 1;
    
    return result;
}
