/*@
    requires ((x) * (x) <= 2147483647 && (x) * (x) >= -2147483648);
    ensures \result == x * x;
*/
int func(int x)
{
    int result;
    int i;

    //@ assert ((x) * (x) <= 2147483647 && (x) * (x) >= -2147483648);
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 100;
        loop invariant ((x) * (x) <= 2147483647 && (x) * (x) >= -2147483648);
        loop assigns i;
    */
    while (i < 100)
    {
        i = i + 1;
    }

    //@ assert x * x <= 2147483647;
    //@ assert x * x >= -2147483648;
    
    result = x * x;
    //@ assert result == x * x;
    return result;
}
