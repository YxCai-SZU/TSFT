#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 50000);
    ensures \result == (n * 100) / 108 || \result == -1;
*/
int func(long n)
{
    long result;
    long i;
    bool found;
    
    result = n * 100;
    i = 0;
    found = false;
    
    /*@
        loop invariant 0 <= result <= n * 100;
        loop invariant 0 <= i <= (n * 100) / 108;
        loop invariant result == n * 100 - 108 * i;
        loop invariant 1 <= n <= 50000;
        loop assigns result, i;
    */
    while (result >= 108)
    {
        //@ assert result >= 108;
        result -= 108;
        i += 1;
    }
    
    if (result == 0)
    {
        found = true;
    }
    
    if (found)
    {
        //@ assert i == (n * 100) / 108;
        return i;
    }
    else
    {
        //@ assert result > 0 && result < 108;
        return -1;
    }
}
